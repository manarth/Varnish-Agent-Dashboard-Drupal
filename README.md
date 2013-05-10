Source
======

* Built from [https://github.com/pbruna/Varnish-Agent-Dashboard](https://github.com/pbruna/Varnish-Agent-Dashboard)


Overview
========

* Agent:     [http://github.com/varnish/vagent2](http://github.com/varnish/vagent2)
             a varnish system for exposing data.
* Dashboard: a HTML real-time viewer.


Prerequisites
=============

1. Varnish (3 or greater)
1. Varnish agent 2
2. Varnish dashboard


Installing Varnish agent 2
==========================

Note: you may need to install some dependencies before you're able to compile   
the Agent source.

* pkg-config
* libvarnishapi-dev
* libmicrohttpd-dev
* libcurl4-openssl-dev
* python-docutils


```
git clone git@github.com:varnish/vagent2.git
cd vagent2
./autogen.sh
./configure
make
```

* Create /etc/varnish/agent_secret

