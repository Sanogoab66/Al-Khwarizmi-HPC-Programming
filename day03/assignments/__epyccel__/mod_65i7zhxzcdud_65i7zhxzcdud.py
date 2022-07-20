def jacobi(a:'float[:,:]', b:'float[:]', x:'float[:]', n:'int', eps:'float'):

#     print("Execution of Jacobi in parallel with", nb_tasks, "threads")
    # Jacobi method resolution
    import numpy as np
    import math
     #$ omp parallel num_threads(8)
     #$ omp single   
    x_courant = np.empty(n, dtype=np.double)
    #$ omp end single
    iteration = 0
    while(1):
        iteration += 1
        #$ omp master
        for i in range(n):
            x_courant[i] = 0
            for j in range(i):
                x_courant[i] += a[ j, i ] * x[j]

            for j in range(i + 1, n):
                x_courant[i] += a[ j, i ] * x[j]

            x_courant[i] = (b[i] - x_courant[i]) / a[ i, i ]
        #$ omp end master
        #$ omp barrier 
        
        # Convergence test
        absmax = 0.
        for i in range(n):
            curr = math.fabs(x[i] - x_courant[i])
            if curr > absmax:
                absmax = curr
        stand = absmax / n
        if stand <= eps or iteration > n:
            break
        # copy x_courant into x
        #$ omp for 
        for i in range(n):
            x [i] = x_courant[i]
        
        #$ omp end parallel     
    return stand, iteration
