#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include <stdint.h>


double pi(int64_t n, double h);

/*........................................*/


/*........................................*/

/*........................................*/
PyObject *pi_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    int64_t n;
    double h;
    double Pi_calc;
    PyObject *n_tmp;
    PyObject *h_tmp;
    PyObject *Pi_calc_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "n",
        "h",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &n_tmp, &h_tmp))
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
    if (PyIs_NativeFloat(h_tmp))
    {
        h = PyDouble_to_Double(h_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    Pi_calc = pi(n, h);
    Pi_calc_tmp = Double_to_PyDouble(&Pi_calc);
    result = Py_BuildValue("O", Pi_calc_tmp);
    Py_DECREF(Pi_calc_tmp);
    return result;
}
/*........................................*/

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef mod_03ds57ti30c7_03ds57ti30c7_methods[] = {
    {
        "pi",
        (PyCFunction)pi_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot mod_03ds57ti30c7_03ds57ti30c7_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef mod_03ds57ti30c7_03ds57ti30c7_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod_03ds57ti30c7_03ds57ti30c7",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod_03ds57ti30c7_03ds57ti30c7_methods,
    mod_03ds57ti30c7_03ds57ti30c7_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod_03ds57ti30c7_03ds57ti30c7(void)
{
    import_array();
    return PyModuleDef_Init(&mod_03ds57ti30c7_03ds57ti30c7_module);
}
