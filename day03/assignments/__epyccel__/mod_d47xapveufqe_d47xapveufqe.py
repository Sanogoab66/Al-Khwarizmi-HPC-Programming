def jacobi(a:'float[:,:]', b:'float[:]', x:'float[:]', n:'int', eps:'float'):

#     print("Execution of Jacobi in parallel with", nb_tasks, "threads")
    # Jacobi method resolution
    import numpy as np
    import math
    x_courant = np.empty(n, dtype=np.double)
    iteration = 0
    while(1):
        iteration += 1
        #$ omp parallel num_threads=4
        #$ omp sections nowait 
        #$ omp section
        for i in range(n):
            x_courant[i] = 0
            for j in range(i):
                x_courant[i] += a[ j, i ] * x[j]

            for j in range(i + 1, n):
                x_courant[i] += a[ j, i ] * x[j]

            x_courant[i] = (b[i] - x_courant[i]) / a[ i, i ]
         #$ omp end section 
        
        # Convergence test
        absmax = 0.
        #$ omp  section
        for i in range(n):
            curr = math.fabs(x[i] - x_courant[i])
            if curr > absmax:
                absmax = curr
        stand = absmax / n
        if stand <= eps or iteration > n:
            break
        #$ omp end section
        
        # copy x_courant into x
        #$ omp section
        for i in range(n):
            x [i] = x_courant[i]
        #$ omp end section 
        #$ omp end sections 
        #$ omp end parallel     
    return stand, iteration
