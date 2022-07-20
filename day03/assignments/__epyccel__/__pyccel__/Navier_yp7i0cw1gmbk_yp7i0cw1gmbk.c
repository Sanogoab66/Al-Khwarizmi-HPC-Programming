#include "Navier_yp7i0cw1gmbk_yp7i0cw1gmbk.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"
#include <math.h>


/*........................................*/
int64_t build_up_b_numba(t_ndarray b, int64_t rho, double dt, t_ndarray u, t_ndarray v, double dx, double dy, int64_t num)
{
    int64_t i_0001;
    int64_t i_0002;
    /*fill the update of b*/
    #pragma omp parallel num_threads(num)
    {
        for (i_0001 = 0; i_0001 < b.shape[0] - 1 - 1; i_0001 += 1)
        {
            for (i_0002 = 0; i_0002 < b.shape[1] - 1 - 1; i_0002 += 1)
            {
                GET_ELEMENT(b, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) = rho * (1 / dt * ((GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 2) - GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) / (2 * dx) + (GET_ELEMENT(v, nd_double, (int64_t)i_0001 + 2, (int64_t)i_0002 + 1) - GET_ELEMENT(v, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)) / (2 * dy)) - pow(((GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 2) - GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) / (2 * dx)), 2.0) - 2 * ((GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 2, (int64_t)i_0002 + 1) - GET_ELEMENT(u, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)) / (2 * dy) * (GET_ELEMENT(v, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 2) - GET_ELEMENT(v, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) / (2 * dx)) - pow(((GET_ELEMENT(v, nd_double, (int64_t)i_0001 + 2, (int64_t)i_0002 + 1) - GET_ELEMENT(v, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)) / (2 * dy)), 2.0));
            }
        }
    }
    return 0;
}
/*........................................*/
/*........................................*/
int64_t pressure_poisson_numba(t_ndarray p, double dx, double dy, t_ndarray b, int64_t nit, int64_t num)
{
    t_ndarray pn = {.shape = NULL};
    int64_t m;
    int64_t i_0003;
    int64_t i_0004;
    #pragma omp parallel num_threads(num)
    {
        pn = array_create(2, (int64_t[]){p.shape[0], p.shape[1]}, nd_double);
        for (m = 0; m < nit; m += 1)
        {
            for (i_0003 = 0; i_0003 < p.shape[0]; i_0003 += 1)
            {
                for (i_0004 = 0; i_0004 < p.shape[1]; i_0004 += 1)
                {
                    GET_ELEMENT(pn, nd_double, (int64_t)i_0003, (int64_t)i_0004) = GET_ELEMENT(p, nd_double, (int64_t)i_0003, (int64_t)i_0004);
                }
            }
            for (i_0003 = 0; i_0003 < p.shape[0] - 1 - 1; i_0003 += 1)
            {
                for (i_0004 = 0; i_0004 < p.shape[1] - 1 - 1; i_0004 += 1)
                {
                    GET_ELEMENT(p, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 1) = ((GET_ELEMENT(pn, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 2) + GET_ELEMENT(pn, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004)) * pow(dy, 2.0) + (GET_ELEMENT(pn, nd_double, (int64_t)i_0003 + 2, (int64_t)i_0004 + 1) + GET_ELEMENT(pn, nd_double, (int64_t)i_0003, (int64_t)i_0004 + 1)) * pow(dx, 2.0)) / (2 * (pow(dx, 2.0) + pow(dy, 2.0))) - pow(dx, 2.0) * pow(dy, 2.0) / (2 * (pow(dx, 2.0) + pow(dy, 2.0))) * GET_ELEMENT(b, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 1);
                }
            }
            for (i_0003 = 0; i_0003 < p.shape[0]; i_0003 += 1)
            {
                GET_ELEMENT(p, nd_double, (int64_t)i_0003, (int64_t)p.shape[1] - 1) = GET_ELEMENT(p, nd_double, (int64_t)i_0003, (int64_t)p.shape[1] - 2);
            }
            for (i_0003 = 0; i_0003 < p.shape[1]; i_0003 += 1)
            {
                GET_ELEMENT(p, nd_double, (int64_t)0, (int64_t)i_0003) = GET_ELEMENT(p, nd_double, (int64_t)1, (int64_t)i_0003);
            }
            for (i_0003 = 0; i_0003 < p.shape[0]; i_0003 += 1)
            {
                GET_ELEMENT(p, nd_double, (int64_t)i_0003, (int64_t)0) = GET_ELEMENT(p, nd_double, (int64_t)i_0003, (int64_t)1);
            }
            for (i_0003 = 0; i_0003 < p.shape[1]; i_0003 += 1)
            {
                GET_ELEMENT(p, nd_double, (int64_t)p.shape[0] - 1, (int64_t)i_0003) = 0;
            }
        }
    }
    free_array(pn);
    return 0;
}
/*........................................*/
/*........................................*/
void cavity_flow_numba(int64_t nt, t_ndarray u, t_ndarray v, double dt, int64_t nx, int64_t ny, double dx, double dy, t_ndarray p, int64_t rho, double nu, int64_t nit, int64_t num)
{
    t_ndarray un = {.shape = NULL};
    t_ndarray vn = {.shape = NULL};
    t_ndarray b = {.shape = NULL};
    int64_t n;
    int64_t Dummy_0001;
    int64_t Dummy_0002;
    int64_t i_0005;
    int64_t i_0006;
    #pragma omp parallel num_threads(num)
    {
        un = array_create(2, (int64_t[]){u.shape[0], u.shape[1]}, nd_double);
        vn = array_create(2, (int64_t[]){v.shape[0], v.shape[1]}, nd_double);
        b = array_create(2, (int64_t[]){ny, nx}, nd_double);
        array_fill((double)0.0, b);
        #pragma omp barrier
        /*fill the update of u and v*/
        for (n = 0; n < nt; n += 1)
        {
            for (i_0005 = 0; i_0005 < u.shape[0]; i_0005 += 1)
            {
                for (i_0006 = 0; i_0006 < u.shape[1]; i_0006 += 1)
                {
                    GET_ELEMENT(un, nd_double, (int64_t)i_0005, (int64_t)i_0006) = GET_ELEMENT(u, nd_double, (int64_t)i_0005, (int64_t)i_0006);
                }
            }
            for (i_0005 = 0; i_0005 < v.shape[0]; i_0005 += 1)
            {
                for (i_0006 = 0; i_0006 < v.shape[1]; i_0006 += 1)
                {
                    GET_ELEMENT(vn, nd_double, (int64_t)i_0005, (int64_t)i_0006) = GET_ELEMENT(v, nd_double, (int64_t)i_0005, (int64_t)i_0006);
                }
            }
            Dummy_0001 = build_up_b_numba(b, rho, dt, u, v, dx, dy, num);
            Dummy_0002 = pressure_poisson_numba(p, dx, dy, b, nit, num);
            for (i_0005 = 0; i_0005 < u.shape[0] - 1 - 1; i_0005 += 1)
            {
                for (i_0006 = 0; i_0006 < u.shape[1] - 1 - 1; i_0006 += 1)
                {
                    GET_ELEMENT(u, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) = GET_ELEMENT(un, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) - GET_ELEMENT(un, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) * dt / dx * (GET_ELEMENT(un, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) - GET_ELEMENT(un, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006)) - GET_ELEMENT(vn, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) * dt / dy * (GET_ELEMENT(un, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) - GET_ELEMENT(un, nd_double, (int64_t)i_0005, (int64_t)i_0006 + 1)) - dt / (2 * rho * dx) * (GET_ELEMENT(p, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 2) - GET_ELEMENT(p, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006)) + nu * (dt / pow(dx, 2.0) * (GET_ELEMENT(un, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 2) - 2 * GET_ELEMENT(un, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) + GET_ELEMENT(un, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006)) + dt / pow(dy, 2.0) * (GET_ELEMENT(un, nd_double, (int64_t)i_0005 + 2, (int64_t)i_0006 + 1) - 2 * GET_ELEMENT(un, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) + GET_ELEMENT(un, nd_double, (int64_t)i_0005, (int64_t)i_0006 + 1)));
                }
            }
            for (i_0005 = 0; i_0005 < v.shape[0] - 1 - 1; i_0005 += 1)
            {
                for (i_0006 = 0; i_0006 < v.shape[1] - 1 - 1; i_0006 += 1)
                {
                    GET_ELEMENT(v, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) = GET_ELEMENT(vn, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) - GET_ELEMENT(un, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) * dt / dx * (GET_ELEMENT(vn, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) - GET_ELEMENT(vn, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006)) - GET_ELEMENT(vn, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) * dt / dy * (GET_ELEMENT(vn, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) - GET_ELEMENT(vn, nd_double, (int64_t)i_0005, (int64_t)i_0006 + 1)) - dt / (2 * rho * dy) * (GET_ELEMENT(p, nd_double, (int64_t)i_0005 + 2, (int64_t)i_0006 + 1) - GET_ELEMENT(p, nd_double, (int64_t)i_0005, (int64_t)i_0006 + 1)) + nu * (dt / pow(dx, 2.0) * (GET_ELEMENT(vn, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 2) - 2 * GET_ELEMENT(vn, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) + GET_ELEMENT(vn, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006)) + dt / pow(dy, 2.0) * (GET_ELEMENT(vn, nd_double, (int64_t)i_0005 + 2, (int64_t)i_0006 + 1) - 2 * GET_ELEMENT(vn, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) + GET_ELEMENT(vn, nd_double, (int64_t)i_0005, (int64_t)i_0006 + 1)));
                }
            }
            for (i_0005 = 0; i_0005 < u.shape[1]; i_0005 += 1)
            {
                GET_ELEMENT(u, nd_double, (int64_t)0, (int64_t)i_0005) = 0;
            }
            for (i_0005 = 0; i_0005 < u.shape[0]; i_0005 += 1)
            {
                GET_ELEMENT(u, nd_double, (int64_t)i_0005, (int64_t)0) = 0;
                GET_ELEMENT(u, nd_double, (int64_t)i_0005, (int64_t)u.shape[1] - 1) = 0;
            }
            for (i_0005 = 0; i_0005 < u.shape[1]; i_0005 += 1)
            {
                GET_ELEMENT(u, nd_double, (int64_t)u.shape[0] - 1, (int64_t)i_0005) = 1;
            }
            for (i_0005 = 0; i_0005 < v.shape[1]; i_0005 += 1)
            {
                GET_ELEMENT(v, nd_double, (int64_t)0, (int64_t)i_0005) = 0;
                GET_ELEMENT(v, nd_double, (int64_t)v.shape[0] - 1, (int64_t)i_0005) = 0;
            }
            for (i_0005 = 0; i_0005 < v.shape[0]; i_0005 += 1)
            {
                GET_ELEMENT(v, nd_double, (int64_t)i_0005, (int64_t)0) = 0;
                GET_ELEMENT(v, nd_double, (int64_t)i_0005, (int64_t)v.shape[1] - 1) = 0;
            }
        }
    }
    return;
}
/*........................................*/

