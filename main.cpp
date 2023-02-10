#include <Python.h>
#include <iostream>

int main() {
  Py_Initialize();
  PyRun_SimpleString("def add(a, b):\n\treturn a + b");
  PyObject *pModule = PyImport_AddModule("__main__");
  PyObject *pFunc = PyObject_GetAttrString(pModule, "add");

  PyObject *pArgs = PyTuple_New(2);
  PyTuple_SetItem(pArgs, 0, PyLong_FromLong(1));
  PyTuple_SetItem(pArgs, 1, PyLong_FromLong(2));

  PyObject *pValue = PyObject_CallObject(pFunc, pArgs);
  long result = PyLong_AsLong(pValue);

  std::cout << "The result is: " << result << "\n";

  Py_Finalize();
  return 0;
}
