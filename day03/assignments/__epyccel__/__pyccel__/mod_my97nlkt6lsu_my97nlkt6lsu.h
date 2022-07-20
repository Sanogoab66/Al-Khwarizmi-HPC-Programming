#ifndef MOD_MY97NLKT6LSU_MY97NLKT6LSU_H
#define MOD_MY97NLKT6LSU_MY97NLKT6LSU_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


int jacobi(t_ndarray a, t_ndarray b, t_ndarray x, int64_t n, double eps, double *stand, int64_t *iteration);
#endif // MOD_MY97NLKT6LSU_MY97NLKT6LSU_H
