def matrix_prod(A:'float[:,:]', B:'float[:,:]', C:'float[:,:]', N:'int', M:'int'):
    from pyccel.stdlib.internal.openmp import omp_get_num_threads
    nb_threads=0
    #$ omp parallel num_threads(2)
    #$ omp for collapse(2)
    for i in range( M ):
        for j in range( N ):
            A[ i, j ] = (i + 1) + (j + 1)

    #$ omp for collapse(2)
    for i in range( N ):
        for j in range( M ):
            B[ i, j ] = (i + 1) - (j + 1)      

    #$ omp for collapse(2)
    for i in range( M ):
        for j in range( M ):
            C[ i, j ] = 0
# Matrix Production
    
    #$ omp for private(j,k)
    for i in range( M ):
        for j in range( M ):
            for k in range( N ):
                C[ i, j ] += A[ i, k ] * B[ k, j ]
    nb_threads= omp_get_num_threads()            
    #$ omp end parallel
    #print("Execution of Matrix production in parallele with",nb_threads, "threads")
    return nb_threads
