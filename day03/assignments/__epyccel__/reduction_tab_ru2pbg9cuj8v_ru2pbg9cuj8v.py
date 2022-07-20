
def threads_num(num:'int'):
    #     complete this function for getting threads num
    from pyccel.stdlib.internal.openmp import omp_set_num_threads
    omp_set_num_threads(num)




def initialize_table(tab:'float[:,:,:]', nmolec:'int', n:'int', nmol:'int'):
         # Initialisation du tableau
         # First-touch pour garantir un fonctionnement optimal sur les systemes NUMA
    #$ omp parallel 
    # num_threads(4)
    threads_num(6)
    #$ omp for private(j,i)
    for k in range(nmolec):
        for j in range(n):
            for i in range(nmol):
                tab[ i,j,k ] = i + j + k
   
    #$ omp end parallel               


    
    
def reduction(tab:'float[:,:,:]', tab1:'float[:]', tab2:'float[:]', nmolec:'int', nmol:'int', n:'int'):
    for k in range(nmolec):
        tab1[:nmol] = 0
        for j in range(n):
            for i in range(nmol):
                tab1[i] = tab1[i] + tab[i,j,k]
        tab2[:nmol] = tab2[:nmol] + 2 * tab1[:nmol]
