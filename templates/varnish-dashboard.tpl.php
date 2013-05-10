    <!-- <div class="navbar navbar-fixed-top navbar-inverse">
      <div class="navbar-inner">
        <div class="container">
          <a class="brand" href="#">Varnish Dashboard</a>
        </div>
      </div>
    </div> -->

    <div class="container">

      <div class="row-fluid">
        <div class="span4">
          <div class="content-box">
            <div class="content-box-header">
              <i class="icon-fire"></i>
              Cache Hit Ratio
            </div>
            <div id="hit-ratio" class="text-center gauge" style="width:250px; height:200px"></div>
          </div>
        </div>
        <div class="span4">
          <div class="content-box">
            <div class="content-box-header">
              <i class="icon-globe"></i>
              Requests
            </div>
            <div id="request-gauge" class="text-center gauge" style="width:250px; height:200px"></div>
          </div>
        </div>
        <div class="span4">
          <div class="content-box">
            <div class="content-box-header">
              <i class="icon-globe"></i>
              Bandwidth
            </div>
            <div id="bandwidth-gauge" class="text-center gauge" style="width:250px; height:200px"></div>
          </div>
        </div>
      </div>

      <div class="row-fluid">
        <div class="span4">
          <div class="content-box">
            <div class="content-box-header">
              <i class="icon-signal"></i>
              Cache Metrics
            </div>
            <div id="cache-metrics-table"></div>
          </div>
        </div>
        <div class="span4">
          <div class="content-box">
            <div class="content-box-header">
              <i class="icon-signal"></i>
              Traffic Metrics
            </div>
            <div id="traffic-metrics-table"></div>
          </div>
        </div>
        <div class="span4">
          <div class="content-box">
            <div class="content-box-header">
              <i class="icon-signal"></i>
              Backend Metrics
            </div>
            <div id="backend-metrics-table"></div>
          </div>
        </div>
      </div>

      <div class="row-fluid">
        <div class="span12">
          <div class="content-box">
            <div class="content-box-header">
              <i class="icon-thumbs-down"></i>
              Backend Requests
            </div>
            <div id="backend_request-table">
              <h2 style="margin-left:35px;"><small>Loading...</small></h2>
            </div>
          </div>
        </div>
      </div>

    </div>
    <div id="push" />
  </div>
</div>
