# Using Python Build Scripts in Ubuntu 18.04

First, you need to install some prerequisites

    sudo apt install build-essential googletest python3-dev
   
then compile and install the library

    sudo python3 setup.py install

After this, you should be able to run the tests using run_gtest.py

    python3 run_gtest.py

If you want to actually call the hello function, load up python3 then import 
it and run it.

    python3
    >>> import hellopython
    >>> hellopython.hello()
    !!!Hello World!!!
    >>> 

Look at setup.py for examples on adding source files to the build. There's also
places in here to add defines that may be needed, and test files.