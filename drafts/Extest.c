#include <python3.6m/Python.h>

int fac(int n) {
    if (n < 2)
        return 1;
    return n * fac(n - 1);
}

static PyObject* Extest_fac(PyObject *self, PyObject *args) {
  int res;
  int num;
  PyObject* retval;

  res = PyArg_ParseTuple(args, "i", &num);
  if (!res) {
    return NULL;
  }
  res = fac(num);
  retval = (PyObject *) Py_BuildValue("i", res);
  return retval;
}

static PyMethodDef
ExtestMethods[] = {
  {"fac", Extest_fac, METH_VARARGS, "calculates the fibonachi number"},
  {NULL, NULL, 0, NULL}
};

static struct PyModuleDef extestmodule = {
  PyModuleDef_HEAD_INIT,
  "extest",
  "",
  -1,
  ExtestMethods
};

PyMODINIT_FUNC PyInit_Extest(void) {
  return PyModule_Create(&extestmodule);
}
    
