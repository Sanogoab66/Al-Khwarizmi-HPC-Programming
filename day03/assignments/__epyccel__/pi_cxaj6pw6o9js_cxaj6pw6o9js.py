
def f(a:'float'):
    return 4.0 / (1. + a * a)

def pi(n:'int', h:'float'):
# print("Execution of PI in parallel with", nb_tasks,"threads")

    #$ omp parallel num_threads(4)
    #$ omp for 
    for k in range(100):
        Pi_calc = 0.
        for i in range(n):
    #$ omp critical        
            x = h * (i + 0.5)
    #$ omp end critical
    
    #$ omp critical 
            Pi_calc += 4.0 / (1. + x * x)
    #$ omp end critical  
    
    #$ omp critical 
        Pi_calc = h * Pi_calc
    #$ omp end critical    
    #$ omp end parallel   
    return Pi_calc
