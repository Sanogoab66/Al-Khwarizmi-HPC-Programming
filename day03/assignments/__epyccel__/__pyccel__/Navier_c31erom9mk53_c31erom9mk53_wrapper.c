#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"
#include "cwrapper_ndarrays.h"


int64_t build_up_b_numba(t_ndarray b, int64_t rho, double dt, t_ndarray u, t_ndarray v, double dx, double dy);
int64_t pressure_poisson_numba(t_ndarray p, double dx, double dy, t_ndarray b, int64_t nit);

/*........................................*/


/*........................................*/

/*........................................*/
PyObject *build_up_b_numba_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    t_ndarray b = {.shape = NULL};
    int64_t rho;
    double dt;
    t_ndarray u = {.shape = NULL};
    t_ndarray v = {.shape = NULL};
    double dx;
    double dy;
    int64_t Out_0001;
    PyArrayObject *b_tmp;
    PyObject *rho_tmp;
    PyObject *dt_tmp;
    PyArrayObject *u_tmp;
    PyArrayObject *v_tmp;
    PyObject *dx_tmp;
    PyObject *dy_tmp;
    PyObject *Out_0001_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "b",
        "rho",
        "dt",
        "u",
        "v",
        "dx",
        "dy",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O!OOO!O!OO", kwlist, &PyArray_Type, &b_tmp, &rho_tmp, &dt_tmp, &PyArray_Type, &u_tmp, &PyArray_Type, &v_tmp, &dx_tmp, &dy_tmp))
    {
        return NULL;
    }
    if (!pyarray_check(b_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        b = pyarray_to_ndarray(b_tmp);
    }
    if (PyIs_NativeInt(rho_tmp))
    {
        rho = PyInt64_to_Int64(rho_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    if (PyIs_NativeFloat(dt_tmp))
    {
        dt = PyDouble_to_Double(dt_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (!pyarray_check(u_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        u = pyarray_to_ndarray(u_tmp);
    }
    if (!pyarray_check(v_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        v = pyarray_to_ndarray(v_tmp);
    }
    if (PyIs_NativeFloat(dx_tmp))
    {
        dx = PyDouble_to_Double(dx_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (PyIs_NativeFloat(dy_tmp))
    {
        dy = PyDouble_to_Double(dy_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    Out_0001 = build_up_b_numba(b, rho, dt, u, v, dx, dy);
    Out_0001_tmp = Int64_to_PyLong(&Out_0001);
    result = Py_BuildValue("O", Out_0001_tmp);
    Py_DECREF(Out_0001_tmp);
    free_pointer(b);
    free_pointer(u);
    free_pointer(v);
    return result;
}
/*........................................*/

/*........................................*/
PyObject *pressure_poisson_numba_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    t_ndarray p = {.shape = NULL};
    double dx;
    double dy;
    t_ndarray b = {.shape = NULL};
    int64_t nit;
    int64_t Out_0002;
    PyArrayObject *p_tmp;
    PyObject *dx_tmp;
    PyObject *dy_tmp;
    PyArrayObject *b_tmp;
    PyObject *nit_tmp;
    PyObject *Out_0002_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "p",
        "dx",
        "dy",
        "b",
        "nit",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O!OOO!O", kwlist, &PyArray_Type, &p_tmp, &dx_tmp, &dy_tmp, &PyArray_Type, &b_tmp, &nit_tmp))
    {
        return NULL;
    }
    if (!pyarray_check(p_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        p = pyarray_to_ndarray(p_tmp);
    }
    if (PyIs_NativeFloat(dx_tmp))
    {
        dx = PyDouble_to_Double(dx_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (PyIs_NativeFloat(dy_tmp))
    {
        dy = PyDouble_to_Double(dy_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (!pyarray_check(b_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        b = pyarray_to_ndarray(b_tmp);
    }
    if (PyIs_NativeInt(nit_tmp))
    {
        nit = PyInt64_to_Int64(nit_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    Out_0002 = pressure_poisson_numba(p, dx, dy, b, nit);
    Out_0002_tmp = Int64_to_PyLong(&Out_0002);
    result = Py_BuildValue("O", Out_0002_tmp);
    Py_DECREF(Out_0002_tmp);
    free_pointer(p);
    free_pointer(b);
    return result;
}
/*........................................*/

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef Navier_c31erom9mk53_c31erom9mk53_methods[] = {
    {
        "build_up_b_numba",
        (PyCFunction)build_up_b_numba_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    {
        "pressure_poisson_numba",
        (PyCFunction)pressure_poisson_numba_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot Navier_c31erom9mk53_c31erom9mk53_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef Navier_c31erom9mk53_c31erom9mk53_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "Navier_c31erom9mk53_c31erom9mk53",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    Navier_c31erom9mk53_c31erom9mk53_methods,
    Navier_c31erom9mk53_c31erom9mk53_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_Navier_c31erom9mk53_c31erom9mk53(void)
{
    import_array();
    return PyModuleDef_Init(&Navier_c31erom9mk53_c31erom9mk53_module);
}
