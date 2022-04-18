def solve_1d_nonlinearconv_pyccel(u:'float[:]', un:'float[:]', nt:'int', nx:'int', dt:'float', dx:'float'):
    #fill the update of u
    for i in range(nt):
        for j in range(nx):un[j]=u[j]
        for  k in range(1,nx):
             u[k]=un[k]-un[k]*(dt/dx)*(un[k]-un[k-1])
    
    return 0
