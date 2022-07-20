#ifndef NAVIER_033BQ8FY4OUH_033BQ8FY4OUH_H
#define NAVIER_033BQ8FY4OUH_033BQ8FY4OUH_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


void build_up_b_numba(t_ndarray b, int64_t rho, double dt, t_ndarray u, t_ndarray v, double dx, double dy);
#endif // NAVIER_033BQ8FY4OUH_033BQ8FY4OUH_H
