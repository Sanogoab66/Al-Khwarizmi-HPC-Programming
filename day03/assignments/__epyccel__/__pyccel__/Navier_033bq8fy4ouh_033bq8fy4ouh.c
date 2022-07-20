#include "Navier_033bq8fy4ouh_033bq8fy4ouh.h"
#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>
#include <math.h>


/*........................................*/
void build_up_b_numba(t_ndarray b, int64_t rho, double dt, t_ndarray u, t_ndarray v, double dx, double dy)
{
    int64_t i_0001;
    int64_t i_0002;
    /*fill the update of b*/
    for (i_0001 = 0; i_0001 < b.shape[0] - 1 - 1; i_0001 += 1)
    {
        for (i_0002 = 0; i_0002 < b.shape[1] - 1 - 1; i_0002 += 1)
        {
            GET_ELEMENT(b, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) = rho * (1 / dt * ((GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 2) - GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) / (2 * dx) + (GET_ELEMENT(v, nd_double, (int64_t)i_0001 + 2, (int64_t)i_0002 + 1) - GET_ELEMENT(v, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)) / (2 * dy)) - pow(((GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 2) - GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) / (2 * dx)), 2.0) - 2 * ((GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 2, (int64_t)i_0002 + 1) - GET_ELEMENT(u, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)) / (2 * dy) * (GET_ELEMENT(v, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 2) - GET_ELEMENT(v, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) / (2 * dx)) - pow(((GET_ELEMENT(v, nd_double, (int64_t)i_0001 + 2, (int64_t)i_0002 + 1) - GET_ELEMENT(v, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)) / (2 * dy)), 2.0));
        }
    }
    return;
}
/*........................................*/

