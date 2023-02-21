#include <Python.h>
#include <iostream>

PyObject *add_func(PyObject *self, PyObject *args) {
  int a, b;
  if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
    return NULL;
  }
  return PyLong_FromLong(a + b);
}

static PyMethodDef my_module_methods[] = {
    {"add", add_func, METH_VARARGS, "Add two integers."},
    {NULL, NULL, 0, NULL}};

static PyModuleDef my_module_def = {PyModuleDef_HEAD_INIT,
                                    "my_module",
                                    "An empty Python module",
                                    -1,
                                    my_module_methods,
                                    NULL,
                                    NULL,
                                    NULL,
                                    NULL};

PyMODINIT_FUNC PyInit_my_module(void) {
  return PyModule_Create(&my_module_def);
}

int main() {
  PyImport_AppendInittab("my_module", &PyInit_my_module);

  Py_Initialize();

  PyObject *pModule = PyImport_ImportModule("my_module");

  PyObject *pFunc = PyObject_GetAttrString(pModule, "add");
  PyObject *pArgs = PyTuple_Pack(2, PyLong_FromLong(1), PyLong_FromLong(2));
  PyObject *pValue = PyObject_CallObject(pFunc, pArgs);

  long result = PyLong_AsLong(pValue);

  std::cout << "The result is: " << result << "\n";

  PyObject *my_dict = PyDict_New();

  int success = 0;
  success += PyDict_SetItem(my_dict, PyUnicode_FromString("Value1"),
                            PyLong_FromLong(1));
  success += PyDict_SetItem(my_dict, PyUnicode_FromString("Value2"),
                            PyLong_FromLong(2));
  success += PyDict_SetItem(my_dict, PyUnicode_FromString("Value3"),
                            PyLong_FromLong(3));

  if (success == 0) {
    PyObject *key = PyUnicode_FromString("Value2");
    if (PyDict_Contains(my_dict, key) == 1) {
      PyObject *value = PyDict_GetItem(my_dict, key);
      long my_value = PyLong_AsLong(value);
      std::cout << "The value in the dictionary is " << my_value << "\n";
    }
  } else {
    std::cout << "Error while creating dictionary.";
  }

  Py_Finalize();
  return 0;
}
