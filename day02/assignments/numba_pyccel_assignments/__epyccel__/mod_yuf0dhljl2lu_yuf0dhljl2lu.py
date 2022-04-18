def solve_1d_burger_pyccel(u:'float[:]', un:'float[:]', nt:'int', nx:'int', dt:'float', dx:'float', nu:'float'):
    #fill the update of u
    for i in range(nt):
        un=u.copy()
        u=np.zeros(len(un))
        for k in range(1,nx-1):
            u[k]= un[k] - un[k]*(dt/dx)*(un[k] - un[k-1]) + (nu*dt/dx**2)*( un[k+1] - 2*un[k] + un[k-1])
    return 0
