<?php
/**
 * @file
 * Varnish dashboard admin pages.
 */

/**
 * Page callback for admin/config/varnish/dashboard.
 *
 * @ingroup forms
 */
function varnish_dashboard_config($form, &$form_state) {
  $form['varnish_dashboard_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Varnish Agent URL'),
    '#description' => t('Provide the URL of the Varnish Agent service. This is typically %default_url.', array('%default_url' => VARNISH_AGENT_DEFAULT_URL)),
    '#default_value' => variable_get('varnish_dashboard_url'),
  );


  $form['credentials'] = array(
    '#type' => 'fieldset',
    '#title' => t('Credentials'),
    '#description' => t('Provide the username and password used by the Varnish <em>Agent</em> service.'),
    '#collapsible' => TRUE,
    '#collapsed' => (bool) variable_get('varnish_dashboard_username'),
  );
  $form['credentials']['varnish_dashboard_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#default_value' => variable_get('varnish_dashboard_username'),
  );
  $form['credentials']['varnish_dashboard_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#default_value' => variable_get('varnish_dashboard_password'),
  );

  return system_settings_form($form);
}

/**
 * Page callback for admin/reports/varnish_dashboard
 */
function varnish_dashboard_page() {
  $module_path = drupal_get_path('module', 'varnish_dashboard');

  return array(
    '#theme' => 'varnish_dashboard',
    '#attached' => array(
      'css' => array(
        "{$module_path}/css/varnish_dashboard.admin.css",
        "{$module_path}/css/bootstrap.css",
      ),
      'js' => array(
        // "{$module_path}/js/lib/jquery-1.9.1.min.js",
        // "{$module_path}/js/lib/bootstrap.min.js",
        "{$module_path}/js/lib/handlebars-1.0.0-rc.3.js",
        "{$module_path}/js/lib/justgage.js",
        "{$module_path}/js/lib/raphael.2.1.0.min.js",
        "{$module_path}/js/app.js",
      ),
    ),
  );
}

/**
 * Proxy for the Agent requests.
 */
function varnish_dashboard_proxy() {
  $agent_url = variable_get('varnish_dashboard_url', VARNISH_AGENT_DEFAULT_URL);

  // Use the incoming request information to build a proxy request to the
  // varnish agent backend.
  $request_url = $agent_url . implode('/', func_get_args());

  // Embed the username/password into the request URL.
  $username = variable_get('varnish_dashboard_username');
  $password = variable_get('varnish_dashboard_password');
  $parts = explode('://', $request_url, 2);
  $request_url = $parts[0] . "://{$username}:{$password}@" . $parts[1];

  $response = drupal_http_request($request_url, array(
    'method' => $_SERVER['REQUEST_METHOD'], 
  ));

  if ($response && empty($response->error)) {
    if (!empty($response->headers['content-type'])) {
      drupal_add_http_header('content-type', $response->headers['content-type']);
    }
    if (!empty($response->headers['content-length'])) {
      drupal_add_http_header('content-length', $response->headers['content-length']);
    }

    echo $response->data;
    return NULL;
  }

  // Failure - report an error.
  drupal_add_http_header('Status', '500 Server error');
}
