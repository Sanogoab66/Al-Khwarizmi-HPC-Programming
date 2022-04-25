#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include <stdint.h>


int64_t bind_c_factorial_itr(int64_t n);

/*........................................*/


/*........................................*/

/*........................................*/
PyObject *factorial_itr_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    int64_t n;
    int64_t k;
    PyObject *n_tmp;
    PyObject *k_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "n",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O", kwlist, &n_tmp))
    {
        return NULL;
    }
    if (PyIs_NativeInt(n_tmp))
    {
        n = PyInt64_to_Int64(n_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    k = bind_c_factorial_itr(n);
    k_tmp = Int64_to_PyLong(&k);
    result = Py_BuildValue("O", k_tmp);
    Py_DECREF(k_tmp);
    return result;
}
/*........................................*/

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef mod_czou4pr6u5f6_czou4pr6u5f6_methods[] = {
    {
        "factorial_itr",
        (PyCFunction)factorial_itr_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot mod_czou4pr6u5f6_czou4pr6u5f6_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef mod_czou4pr6u5f6_czou4pr6u5f6_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod_czou4pr6u5f6_czou4pr6u5f6",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod_czou4pr6u5f6_czou4pr6u5f6_methods,
    mod_czou4pr6u5f6_czou4pr6u5f6_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod_czou4pr6u5f6_czou4pr6u5f6(void)
{
    import_array();
    return PyModuleDef_Init(&mod_czou4pr6u5f6_czou4pr6u5f6_module);
}
