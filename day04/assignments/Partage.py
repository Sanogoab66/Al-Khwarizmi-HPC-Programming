
from mpi4py import MPI
k = int(input('give a number: '))
#k = 10
comm = MPI.COMM_WORLD
taille = comm.Get_size()
rang = comm.Get_rank()
for i in range(taille-1):
    comm.send(k,dest=i+1,tag=99)
    recvbuf = comm.recv(source = i,tag=99)
    print(f'process {i+1} received {recvbuf} by process {i}')
    
