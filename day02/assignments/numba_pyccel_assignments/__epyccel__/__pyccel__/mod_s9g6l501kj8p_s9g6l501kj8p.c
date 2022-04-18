#include "mod_s9g6l501kj8p_s9g6l501kj8p.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"
#include <math.h>


/*........................................*/
int64_t solve_1d_burger_pyccel(t_ndarray u, t_ndarray un, int64_t nt, int64_t nx, double dt, double dx, double nu)
{
    int64_t i;
    int64_t j;
    int64_t k;
    /*fill the update of u*/
    for (i = 0; i < nt; i += 1)
    {
        for (j = 0; j < nx; j += 1)
        {
            GET_ELEMENT(un, nd_double, (int64_t)j) = GET_ELEMENT(u, nd_double, (int64_t)j);
        }
        for (j = 0; j < nx; j += 1)
        {
            GET_ELEMENT(u, nd_double, (int64_t)j) = 0;
        }
        for (k = 1; k < nx - 1; k += 1)
        {
            GET_ELEMENT(u, nd_double, (int64_t)k) = GET_ELEMENT(un, nd_double, (int64_t)k) - GET_ELEMENT(un, nd_double, (int64_t)k) * (dt / dx) * (GET_ELEMENT(un, nd_double, (int64_t)k) - GET_ELEMENT(un, nd_double, (int64_t)k - 1)) + nu * dt / pow(dx, 2.0) * (GET_ELEMENT(un, nd_double, (int64_t)k + 1) - 2 * GET_ELEMENT(un, nd_double, (int64_t)k) + GET_ELEMENT(un, nd_double, (int64_t)k - 1));
        }
    }
    return 0;
}
/*........................................*/

