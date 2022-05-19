def pi(n:'int', h:'float'):
# print("Execution of PI in parallel with", nb_tasks,"threads")
    #$ omp parallel num_threads(16)
    #$ omp for 
    for k in range(100):
        Pi_calc = 0.
        for i in range(n):
            x = h * (i + 0.5)
            Pi_calc += 4.0 / (1. + x * x)

        Pi_calc = h * Pi_calc
    #$ omp end parallel   
    return Pi_calc
