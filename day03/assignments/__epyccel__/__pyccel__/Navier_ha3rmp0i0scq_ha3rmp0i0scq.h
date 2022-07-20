#ifndef NAVIER_HA3RMP0I0SCQ_HA3RMP0I0SCQ_H
#define NAVIER_HA3RMP0I0SCQ_HA3RMP0I0SCQ_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t build_up_b_numba(t_ndarray b, int64_t rho, double dt, t_ndarray u, t_ndarray v, double dx, double dy);
int64_t pressure_poisson_numba(t_ndarray p, double dx, double dy, t_ndarray b, int64_t nit);
void cavity_flow_numba(int64_t nt, t_ndarray u, t_ndarray v, double dt, int64_t nx, int64_t ny, double dx, double dy, t_ndarray p, int64_t rho, double nu, int64_t nit);
#endif // NAVIER_HA3RMP0I0SCQ_HA3RMP0I0SCQ_H
