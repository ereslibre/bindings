#include <Python.h>

static PyObject *mine_add(PyObject *self, PyObject *args)
{
    int a;
    int b;
    if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
        return 0;
    }
    return Py_BuildValue("i", a + b);
}

static PyMethodDef mine_methods[] = {
    { "add", (PyCFunction) mine_add, METH_VARARGS, 0 },
    { 0, 0, 0, 0 }
};

PyMODINIT_FUNC initmine()
{
    Py_InitModule3("mine", mine_methods, "Extension module");
}
