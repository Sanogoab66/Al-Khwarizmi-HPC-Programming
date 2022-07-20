

from mpi4py import MPI

comm = MPI.COMM_WORLD
taille = comm.Get_size()
rang = comm.Get_rank()
print(f'Hello from the rank {rang} process')
if rang ==taille-1:
    print(f'Parallel execution of hello_world with {taille} process')
