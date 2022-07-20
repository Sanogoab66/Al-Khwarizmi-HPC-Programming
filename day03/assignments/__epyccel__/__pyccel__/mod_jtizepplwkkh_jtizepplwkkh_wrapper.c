#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include <stdint.h>


int64_t bind_c_threads_num(void);

/*........................................*/


/*........................................*/

/*........................................*/
PyObject *threads_num_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    int64_t n;
    PyObject *n_tmp;
    PyObject *result;
    static char *kwlist[] = {
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "", kwlist))
    {
        return NULL;
    }
    n = bind_c_threads_num();
    n_tmp = Int64_to_PyLong(&n);
    result = Py_BuildValue("O", n_tmp);
    Py_DECREF(n_tmp);
    return result;
}
/*........................................*/

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef mod_jtizepplwkkh_jtizepplwkkh_methods[] = {
    {
        "threads_num",
        (PyCFunction)threads_num_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot mod_jtizepplwkkh_jtizepplwkkh_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef mod_jtizepplwkkh_jtizepplwkkh_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod_jtizepplwkkh_jtizepplwkkh",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod_jtizepplwkkh_jtizepplwkkh_methods,
    mod_jtizepplwkkh_jtizepplwkkh_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod_jtizepplwkkh_jtizepplwkkh(void)
{
    import_array();
    return PyModuleDef_Init(&mod_jtizepplwkkh_jtizepplwkkh_module);
}
