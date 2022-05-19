#ifndef MOD_KF3D989A8550_KF3D989A8550_H
#define MOD_KF3D989A8550_KF3D989A8550_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


int jacobi(t_ndarray a, t_ndarray b, t_ndarray x, int64_t n, double eps, double *stand, int64_t *iteration);
#endif // MOD_KF3D989A8550_KF3D989A8550_H
