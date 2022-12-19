#include <iostream>

#include <python3.10/Python.h>
#include <vector>

int main()
{
    std::cout << "Hello from C++!\n";

    Py_Initialize();

    PyRun_SimpleString("print('Hello from Python!')");
    PyRun_SimpleString("i = 10");

    PyObject *mainModule = PyImport_AddModule("__main__");
    PyObject *var_i = PyObject_GetAttrString(mainModule, "i");

    int i = PyLong_AS_LONG(var_i);

    std::cout <<"var i is " << i << "\n";

    Py_Finalize();

    return 0;
}