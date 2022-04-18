#ifndef MOD_4DJVOZJ2NNOQ_4DJVOZJ2NNOQ_H
#define MOD_4DJVOZJ2NNOQ_4DJVOZJ2NNOQ_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t solve_1d_burger_pyccel(t_ndarray u, t_ndarray un, int64_t nt, int64_t nx, double dt, double dx, double nu);
#endif // MOD_4DJVOZJ2NNOQ_4DJVOZJ2NNOQ_H