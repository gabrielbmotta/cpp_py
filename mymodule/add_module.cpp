#include <Python.h>

static PyObject *add(PyObject *self, PyObject *args) {
  PyObject *list;
  if (!PyArg_ParseTuple(args, "O", &list)) {
    return NULL;
  }
  if (!PyList_Check(list)) {
    PyErr_SetString(PyExc_TypeError, "Argument must be a list.");
    return NULL;
  }
  double sum = 0;
  Py_ssize_t size = PyList_Size(list);
  for (Py_ssize_t i = 0; i < size; i++) {
    PyObject *item = PyList_GetItem(list, i);
    if (!PyNumber_Check(item)) {
      PyErr_SetString(PyExc_TypeError, "All items in list must be numbers.");
      return NULL;
    }
    double val = PyFloat_AsDouble(item);
    sum += val;
  }
  return Py_BuildValue("f", sum);
}

static PyMethodDef add_methods[] = {
    {"add", add, METH_VARARGS, "Add all the numbers in a list."},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef add_module = {
    PyModuleDef_HEAD_INIT, "add_numbers",
    "Module that provides a function to add numbers.", -1, add_methods};

PyMODINIT_FUNC PyInit_add_module(void) { return PyModule_Create(&add_module); }
