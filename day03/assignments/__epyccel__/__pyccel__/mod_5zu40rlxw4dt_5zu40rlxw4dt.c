#include "mod_5zu40rlxw4dt_5zu40rlxw4dt.h"
#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


/*........................................*/
void matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M)
{
    int64_t i;
    int64_t j;
    int64_t k;
    #pragma omp parallel num_threads(6)
    {
        #pragma omp sections nowait
        {
            #pragma omp section
            {
                for (i = 0; i < M; i += 1)
                {
                    for (j = 0; j < N; j += 1)
                    {
                        GET_ELEMENT(A, nd_double, (int64_t)i, (int64_t)j) = i + 1 + (j + 1);
                    }
                }
            }
            #pragma omp section
            {
                for (i = 0; i < N; i += 1)
                {
                    for (j = 0; j < M; j += 1)
                    {
                        GET_ELEMENT(B, nd_double, (int64_t)i, (int64_t)j) = i + 1 - (j + 1);
                    }
                }
            }
            #pragma omp section
            {
                for (i = 0; i < M; i += 1)
                {
                    for (j = 0; j < M; j += 1)
                    {
                        GET_ELEMENT(C, nd_double, (int64_t)i, (int64_t)j) = 0;
                    }
                }
            }
        }
        /*Matrix Production*/
        #pragma omp for private(j, k)
        for (i = 0; i < M; i += 1)
        {
            for (j = 0; j < M; j += 1)
            {
                for (k = 0; k < N; k += 1)
                {
                    GET_ELEMENT(C, nd_double, (int64_t)i, (int64_t)j) += GET_ELEMENT(A, nd_double, (int64_t)i, (int64_t)k) * GET_ELEMENT(B, nd_double, (int64_t)k, (int64_t)j);
                }
            }
        }
    }
}
/*........................................*/
