#ifndef MOD_ACSAR0JVGCEC_ACSAR0JVGCEC_H
#define MOD_ACSAR0JVGCEC_ACSAR0JVGCEC_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


int jacobi(t_ndarray a, t_ndarray b, t_ndarray x, int64_t n, double eps, double *stand, int64_t *iteration);
#endif // MOD_ACSAR0JVGCEC_ACSAR0JVGCEC_H
