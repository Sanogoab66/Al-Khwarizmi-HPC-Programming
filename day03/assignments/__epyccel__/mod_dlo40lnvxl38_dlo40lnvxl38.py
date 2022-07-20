def threads_num():
    #     complete your function
    from pyccel.stdlib.internal.openmp import omp_get_num_threads
    return omp_get_num_threads()
