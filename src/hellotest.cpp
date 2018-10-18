/*
 * hellotest.cpp
 *
 *  Created on: Oct 17, 2018
 *      Author: kazriko
 */

#include <Python.h>
#include "gtest/gtest.h"
#include "hellopython.h"


TEST(HelloPythonTest, testHelloContent)
    {
    ASSERT_STREQ(get_greetings(), "!!!Hello World!!!");
    }