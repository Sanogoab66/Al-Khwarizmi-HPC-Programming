#include "mod_4djvozj2nnoq_4djvozj2nnoq.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"
#include <math.h>


/*........................................*/
int64_t solve_1d_burger_pyccel(t_ndarray u, t_ndarray un, int64_t nt, int64_t nx, double dt, double dx, double nu)
{
    int64_t i;
    int64_t k;
    /*fill the update of u*/
    for (i = 0; i < nt; i += 1)
    {
        for (i = 0; i < nx; i += 1)
        {
            GET_ELEMENT(un, nd_double, (int64_t)i) = GET_ELEMENT(u, nd_double, (int64_t)i);
        }
        /*u=np.zeros(len(un))*/
        for (k = 1; k < nx - 1; k += 1)
        {
            GET_ELEMENT(u, nd_double, (int64_t)k) = GET_ELEMENT(un, nd_double, (int64_t)k) - GET_ELEMENT(un, nd_double, (int64_t)k) * (dt / dx) * (GET_ELEMENT(un, nd_double, (int64_t)k) - GET_ELEMENT(un, nd_double, (int64_t)k - 1)) + nu * dt / pow(dx, 2.0) * (GET_ELEMENT(un, nd_double, (int64_t)k + 1) - 2 * GET_ELEMENT(un, nd_double, (int64_t)k) + GET_ELEMENT(un, nd_double, (int64_t)k - 1));
        }
    }
    return 0;
}
/*........................................*/

