#ifndef NAVIER_C31EROM9MK53_C31EROM9MK53_H
#define NAVIER_C31EROM9MK53_C31EROM9MK53_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t build_up_b_numba(t_ndarray b, int64_t rho, double dt, t_ndarray u, t_ndarray v, double dx, double dy);
int64_t pressure_poisson_numba(t_ndarray p, double dx, double dy, t_ndarray b, int64_t nit);
#endif // NAVIER_C31EROM9MK53_C31EROM9MK53_H
