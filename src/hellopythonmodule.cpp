/*
 * hellopythonmodule.cpp
 *
 *  Created on: Oct 17, 2018
 *      Author: kazriko
 */

using namespace std;
#include <Python.h>
#include "hellopython.h"
#ifdef GOOGLETEST
#include <gtest/gtest.h>
#endif

static PyObject * py_run_gtest(PyObject * self, PyObject * args)
    {
    PyObject * inarglist;
#ifdef GOOGLETEST
    // inarglist is borrowed.
    if (!PyArg_ParseTuple(args, "O", &inarglist)) return NULL;

    int argc = (int) PyList_Size(inarglist);
    char ** cargs = new char*[argc];
    for (int x=0;x<argc;x++)
        {
        // Borrowed, we don't need to decref
        PyObject * unicode = PyList_GetItem(inarglist, x);
        // Newref, decref later.
        PyObject * byteobj = PyUnicode_AsUTF8String(unicode);
        // bytesarray is Part of byteobj, so requires it to stick around.
        char * bytesarray = PyBytes_AsString(byteobj);
        int len = PyBytes_Size(byteobj);
        cargs[x] = new char[len+1];
        // Last line that needs byteobj
        memset(cargs[x], '\0', len+1);
        strncpy(cargs[x], bytesarray, len);
        Py_DECREF(byteobj);
        }

    ::testing::InitGoogleTest(&argc, cargs);
    int returnv = RUN_ALL_TESTS();

    if (PyErr_Occurred())
        {
        fprintf(stderr, "Err Occurred in Unit tests.");
        PyErr_Print();
        PyErr_Clear();
        }


    return PyLong_FromLong(returnv);
#else
    PyErr_SetString(PyExc_RuntimeError, "Googletest has not been compiled in.");
    return NULL;
#endif
    }

static PyObject * py_hello(PyObject * dummy, PyObject * args)
    {
    hello();
    Py_INCREF(Py_None);
    return Py_None;
    }



static PyMethodDef HelloMethods[] = \
    {
    {"hello", py_hello, METH_NOARGS, "Say hello."},
    {"run_gtest", py_run_gtest, METH_VARARGS, "Run the GTests."},
    {NULL, NULL, 0, NULL}
    };
    
static struct PyModuleDef hellopythonmodule =
    {
    PyModuleDef_HEAD_INIT,
    "hellopython",
    "Demonstration of compiling C++ code into Python modules.",
    -1,
    HelloMethods
    };

PyMODINIT_FUNC PyInit_hellopython(void)
    {
    PyObject *m;
    m = PyModule_Create(&hellopythonmodule);
    if (m == NULL) return NULL;
    return m;
    }