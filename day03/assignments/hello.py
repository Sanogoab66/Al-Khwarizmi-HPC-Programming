# write your program here

from pyccel.stdlib.internal.openmp  import omp_get_thread_num
if __name__=="__main__":
#$ omp parallel firstprivate(rank,a)
   a=0
   rank=omp_get_thread_num()
   print(f'Hello from the rank {rank} thread')
   a+=1
#$ omp end parallel    

print(f'Parallel execution of hello_world with {a}  threads')
