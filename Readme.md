About
=====

FXCM-API aims to create a usable Python interface to the ForexConnect C++ API.

The plan is to model many of the available methods from the ForexConnect C++ API into small modular classes and make them available to Python code by using Boost::Python to compile into a Python module.
 

  

Requirements
============

* libyaml development files (for the test config)


Installation
============

* First download the the ForexConnectAPI package from [http://fxcodebase.com/wiki/index.php/Download]. [http://fxcodebase.com/bin/forexconnect/1.3.1/ForexConnectAPI-1.3.1-Linux-x86_64.tar.gz Tar Link] I used version 1.3.1, later versions may work, but earlier will not.
* Once you have extracted the files, you will need to copy all files from the extracted includes directory and put them into the projects include/ directory 



Example Installation
--------------------
    # Get all the include files
    tar zxvf ForexConnectAPI-1.3.1-Linux-x86_64.tar.gz
    cd ForexConnectAPI-1.3.1-Linux-x86_64/
    cp -a include/* <ProjectDirectory>;/FXCM-API/include/
    cp -a samples/cpp/sample_tools/include/* <ProjectDirectory>/FXCM-API/include/

    # Build and copy the shared libraries
    cp -L lib/*.so <ProjectDirectory>;/FXCM-API/lib/
    cd samples/cpp/sample_tools/
    ./fxbuild.sh
    cp lib/libsample_tools.so <ProjectDirectory>;/FXCM-API/lib/

    # Install the libyaml libraries
    sudo apt-get install libyaml-dev

    # Optional - But recommended
    cd <ProjectDirectory>;/FXCM-API/lib/
    sudo cp *.so /usr/lib
    
    # Test build
    make clean test


    
Configuration
=============
    
* If you want to run the tests, you'll need to copy the config/config.yaml.example to config/config.yaml. You are able to specify a demo account for both the required logins.


Todo
====

There are plenty of ways to help out, testing is always welcome

* configure script (Or an overhaul to the build system)
* Test for memory leaks - It's not yet been throw valgrind much.
