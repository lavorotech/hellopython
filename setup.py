#!/usr/bin/env PYTHON3

from distutils.core import Extension, setup
import os
import sys

sources=['src/hellopython.cpp',
         'src/hellopythonmodule.cpp']

if os.path.exists("/usr/src/gtest"):
    gtest_dir = "/usr/src/gtest"
elif os.path.exists("/usr/src/googletest/googletest"):
    gtest_dir = "/usr/src/googletest/googletest"
    
macros = [("PYTHON",1)]

if gtest_dir is not None:
    sources += ["src/hellotest.cpp",
    gtest_dir+"/src/gtest-all.cc"
    ]
    macros = macros + [("GOOGLETEST", 1)]

sys.path.append('.')
hellopython = Extension('hellopython',
                        define_macros=macros,
                        include_dirs = ['inc', gtest_dir], 
                        sources=sources
                        )

if __name__ == "__main__":
    setup(name="hellopython"
          ,version="1.0"
          ,description="Python C++ Demo"
          ,ext_modules=[hellopython]
          )