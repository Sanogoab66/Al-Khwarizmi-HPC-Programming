# write your program here

from mpi4py import MPI
comm=MPI.COMM_WORLD()
taille=COMM.Get_size()
rank=COMM.Get_rank()
print(f'Hello from the rank {rank} process')
print(f'Parallel execution of hello_world with {taille} process')
