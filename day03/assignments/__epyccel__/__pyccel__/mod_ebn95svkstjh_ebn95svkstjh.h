#ifndef MOD_EBN95SVKSTJH_EBN95SVKSTJH_H
#define MOD_EBN95SVKSTJH_EBN95SVKSTJH_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


void navier_openmp(int64_t nit, int64_t nt, t_ndarray u, t_ndarray un, t_ndarray b, t_ndarray v, t_ndarray vn, double dt, int64_t nx, int64_t ny, double dx, double dy, t_ndarray p, t_ndarray pn, int64_t rho, double nu, int64_t num);
#endif // MOD_EBN95SVKSTJH_EBN95SVKSTJH_H
