def solve_1d_diff_pyccel(u:'float[:]', un:'float[:]',nt:'int', nx:'int', dt:'float', dx:'float', nu:'float'):
    for i in range(nt):
        for k in range(nx):un[k]=u[k]
        for j in range(1,nx-1):
            u[j]=un[j]+(nu*dt/dx**2)*(un[j+1]-2*un[j]+un[j-1])  
    
    #fill the update of u
    return 0
