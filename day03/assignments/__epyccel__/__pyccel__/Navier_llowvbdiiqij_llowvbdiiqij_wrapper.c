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
int64_t cavity_flow_numba(int64_t nt, t_ndarray u, t_ndarray v, double dt, int64_t nx, int64_t ny, double dx, double dy, t_ndarray p, int64_t rho, double nu, int64_t nit);

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

/*........................................*/
PyObject *cavity_flow_numba_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    int64_t nt;
    t_ndarray u = {.shape = NULL};
    t_ndarray v = {.shape = NULL};
    double dt;
    int64_t nx;
    int64_t ny;
    double dx;
    double dy;
    t_ndarray p = {.shape = NULL};
    int64_t rho;
    double nu;
    int64_t nit;
    int64_t Out_0003;
    PyObject *nt_tmp;
    PyArrayObject *u_tmp;
    PyArrayObject *v_tmp;
    PyObject *dt_tmp;
    PyObject *nx_tmp;
    PyObject *ny_tmp;
    PyObject *dx_tmp;
    PyObject *dy_tmp;
    PyArrayObject *p_tmp;
    PyObject *rho_tmp;
    PyObject *nu_tmp;
    PyObject *nit_tmp;
    PyObject *Out_0003_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "nt",
        "u",
        "v",
        "dt",
        "nx",
        "ny",
        "dx",
        "dy",
        "p",
        "rho",
        "nu",
        "nit",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO!O!OOOOOO!OOO", kwlist, &nt_tmp, &PyArray_Type, &u_tmp, &PyArray_Type, &v_tmp, &dt_tmp, &nx_tmp, &ny_tmp, &dx_tmp, &dy_tmp, &PyArray_Type, &p_tmp, &rho_tmp, &nu_tmp, &nit_tmp))
    {
        return NULL;
    }
    if (PyIs_NativeInt(nt_tmp))
    {
        nt = PyInt64_to_Int64(nt_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
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
    if (PyIs_NativeFloat(dt_tmp))
    {
        dt = PyDouble_to_Double(dt_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (PyIs_NativeInt(nx_tmp))
    {
        nx = PyInt64_to_Int64(nx_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    if (PyIs_NativeInt(ny_tmp))
    {
        ny = PyInt64_to_Int64(ny_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
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
    if (!pyarray_check(p_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        p = pyarray_to_ndarray(p_tmp);
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
    if (PyIs_NativeFloat(nu_tmp))
    {
        nu = PyDouble_to_Double(nu_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
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
    Out_0003 = cavity_flow_numba(nt, u, v, dt, nx, ny, dx, dy, p, rho, nu, nit);
    Out_0003_tmp = Int64_to_PyLong(&Out_0003);
    result = Py_BuildValue("O", Out_0003_tmp);
    Py_DECREF(Out_0003_tmp);
    free_pointer(u);
    free_pointer(v);
    free_pointer(p);
    return result;
}
/*........................................*/

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef Navier_llowvbdiiqij_llowvbdiiqij_methods[] = {
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
    {
        "cavity_flow_numba",
        (PyCFunction)cavity_flow_numba_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot Navier_llowvbdiiqij_llowvbdiiqij_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef Navier_llowvbdiiqij_llowvbdiiqij_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "Navier_llowvbdiiqij_llowvbdiiqij",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    Navier_llowvbdiiqij_llowvbdiiqij_methods,
    Navier_llowvbdiiqij_llowvbdiiqij_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_Navier_llowvbdiiqij_llowvbdiiqij(void)
{
    import_array();
    return PyModuleDef_Init(&Navier_llowvbdiiqij_llowvbdiiqij_module);
}