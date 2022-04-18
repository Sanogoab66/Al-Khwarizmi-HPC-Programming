#ifndef MOD_CYNV0SY6WVSO_CYNV0SY6WVSO_H
#define MOD_CYNV0SY6WVSO_CYNV0SY6WVSO_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t solve_1d_linearconv_pyccel(t_ndarray u, t_ndarray un, int64_t nt, int64_t nx, double dt, double dx, double c);
#endif // MOD_CYNV0SY6WVSO_CYNV0SY6WVSO_H
