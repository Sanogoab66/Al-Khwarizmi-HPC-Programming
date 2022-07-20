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
    int64_t Out_0001;
    PyObject *Out_0001_tmp;
    PyObject *result;
    static char *kwlist[] = {
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "", kwlist))
    {
        return NULL;
    }
    Out_0001 = bind_c_threads_num();
    Out_0001_tmp = Int64_to_PyLong(&Out_0001);
    result = Py_BuildValue("O", Out_0001_tmp);
    Py_DECREF(Out_0001_tmp);
    return result;
}
/*........................................*/

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef mod_xqjrwbwf7wp1_xqjrwbwf7wp1_methods[] = {
    {
        "threads_num",
        (PyCFunction)threads_num_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot mod_xqjrwbwf7wp1_xqjrwbwf7wp1_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef mod_xqjrwbwf7wp1_xqjrwbwf7wp1_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod_xqjrwbwf7wp1_xqjrwbwf7wp1",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod_xqjrwbwf7wp1_xqjrwbwf7wp1_methods,
    mod_xqjrwbwf7wp1_xqjrwbwf7wp1_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod_xqjrwbwf7wp1_xqjrwbwf7wp1(void)
{
    import_array();
    return PyModuleDef_Init(&mod_xqjrwbwf7wp1_xqjrwbwf7wp1_module);
}
