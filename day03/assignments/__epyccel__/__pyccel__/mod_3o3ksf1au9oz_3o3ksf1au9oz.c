#include "mod_3o3ksf1au9oz_3o3ksf1au9oz.h"
#include <stdlib.h>
#include <stdint.h>


/*........................................*/
double pi(int64_t n, double h)
{
    int64_t k;
    int64_t i;
    double x;
    double Pi_calc;
    /*print("Execution of PI in parallel with", nb_tasks,"threads")*/
    #pragma omp parallel
    {
        #pragma omp for
        for (k = 0; k < 100; k += 1)
        {
            Pi_calc = 0.0;
            for (i = 0; i < n; i += 1)
            {
                x = h * (i + 0.5);
                Pi_calc += 4.0 / (1.0 + x * x);
            }
            Pi_calc = h * Pi_calc;
        }
    }
    return Pi_calc;
}
/*........................................*/

