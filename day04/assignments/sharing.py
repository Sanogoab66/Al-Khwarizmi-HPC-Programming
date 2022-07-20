# write your program here

from mpi4py import MPI
k = int(input('give a number: '))
while k > 0:
   comm = MPI.COMM_WORLD
   #taille = comm.Get_size()
   rang = comm.Get_rank()
   if rang == 0:
       sendbuf = k
   else:
       sendbuf = None
   recvbuf = comm.bcast(sendbuf, root=0)
   print(f'Process {rang} got {recvbuf}')
   k = int(input('give a number: '))
   

