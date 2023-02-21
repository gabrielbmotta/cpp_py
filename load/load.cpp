#include <Python.h>
#include <iostream>

int main(int argc, char *argv[]) {
  Py_Initialize();

  PyObject *sys = PyImport_ImportModule("sys");
  PyObject *path = PyObject_GetAttrString(sys, "path");
  PyList_Append(path, PyUnicode_FromString("."));
  Py_DECREF(sys);
  Py_DECREF(path);

  PyObject *pName, *pModule, *pFunc, *pArgs, *pValue;

  // Convert the file name to a Python string
  pName = PyUnicode_DecodeFSDefault("call");

  // Load the module object
  pModule = PyImport_Import(pName);
  Py_DECREF(pName);

  // PyImport_ImportModule("call");

  if (pModule != NULL) {
    // Load the function from the module
    pFunc = PyObject_GetAttrString(pModule, "start");
    if (pFunc && PyCallable_Check(pFunc)) {
      std::cout << "We found the function we were looking for.\n";
      // Prepare the arguments for the function call
      pArgs = PyTuple_New(1);
      PyTuple_SetItem(pArgs, 0, PyLong_FromLong(42));

      // Call the function
      pValue = PyObject_CallObject(pFunc, pArgs);
      if (pValue != NULL) {
        std::cout << "Result of the function call: " << PyLong_AsLong(pValue)
                  << std::endl;
        Py_DECREF(pValue);
      } else {
        Py_DECREF(pFunc);
        Py_DECREF(pModule);
        PyErr_Print();
        return 1;
      }
    } else {
      if (PyErr_Occurred())
        PyErr_Print();
      std::cerr << "Cannot find function: "
                << "function_name" << std::endl;
    }
    Py_XDECREF(pFunc);
    Py_DECREF(pModule);
  } else {
    PyErr_Print();
    return 1;
  }
  Py_Finalize();
  return 0;
}
