def matrix_prod(A:'float[:,:]', B:'float[:,:]', C:'float[:,:]', N:'int', M:'int'):
    
    #$ omp parallel 
    omp_num_threads=4
    #$ omp sections nowait
    #$ omp section
    for i in range( M ):
        for j in range( N ):
            A[ i, j ] = (i + 1) + (j + 1)
    #$ omp end section

    #$ omp section
    for i in range( N ):
        for j in range( M ):
            B[ i, j ] = (i + 1) - (j + 1)
    #$ omp end section        

    #$ omp section 
    for i in range( M ):
        for j in range( M ):
            C[ i, j ] = 0
    #$ omp end section
    #$ omp  end sections
    # Matrix Production
    
    #$ omp for private(j,k)
    for i in range( M ):
        for j in range( M ):
            for k in range( N ):
                C[ i, j ] += A[ i, k ] * B[ k, j ]
    #$ omp end parallel
