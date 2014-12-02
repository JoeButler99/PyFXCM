About
=====

FXMCAPI aims to create a usable Python interface ForexConnect C++ API.

The plan is to model many of the available methods from the ForexConnect C++ API into small  and make them available to Python code by using Boost::Python to compile into a Python module.
 

  

Requirements
============



Installation
============

* First download the the ForexConnectAPI package from [http://fxcodebase.com/wiki/index.php/Download]. [http://fxcodebase.com/bin/forexconnect/1.3.1/ForexConnectAPI-1.3.1-Linux-x86_64.tar.gz Tar Link] I used version 1.3.1, later versions may work, but earlier will not.
* Once you have extracted the files, you will need to copy all files from the extracted includes directory and put them into the projects include/ directory 



Example Installation
--------------------
    # Get all the include files
    tar zxvf ForexConnectAPI-1.3.1-Linux-x86_64.tar.gz
    cd ForexConnectAPI-1.3.1-Linux-x86_64/
    cp -a include/* &lt;ProjectDirectory&gt;/FXCMAPI/include/
    cp -a samples/cpp/sample_tools/include/* &lt;ProjectDirectory&gt;/FXCMAPI/include/

    # Build and copy the shared libraries
    cp -L lib/*.so &lt;ProjectDirectory&gt;/FXCMAPI/lib/
    cd samples/cpp/sample_tools/
    ./fxbuild.sh
    cp lib/libsample_tools.so &lt;ProjectDirectory&gt;/FXCMAPI/lib/

    # Optional - But recomended
    cd &lt;ProjectDirectory&gt;/FXCMAPI/lib/
    sudo cp *.so /usr/lib
    
Configuration
=============
    
* If you want to run the tests, you'll need to copy the config/config.yaml.example to config/config.yaml. You are able to specify a demo account for both the required logins.


Todo
====

There are plenty of ways to help out, testing is always welcome

* configure script (Or an overhaul to the build system)
* Test for memory leaks - It's not yet been throw valgrind much.