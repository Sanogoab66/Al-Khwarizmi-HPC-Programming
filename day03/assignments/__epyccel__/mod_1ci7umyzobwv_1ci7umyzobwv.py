def navier_openmp(nit:'int',nt:'int', u:'float[:,:]',un:'float[:,:]',b:'float[:,:]',v:'float[:,:]', vn:'float[:,:]',dt:'float', nx:'int', ny:'int', dx:'float', dy:'float', p:'float[:,:]', pn:'float[:,:]',rho:'int', nu:'float'):
    #un = u
    #vn = v
    #b = u
   
    #$ omp parallel
    #$ omp for
   
    for n in range(nt):
        un[:,:] = u[:,:]
        vn[:,:] = v[:,:]
       

    #$ omp sections
    #$ omp section
   
     # Calcul de p
        row, col = p.shape
        b[1:-1, 1:-1] = (rho * (1 / dt *
                        ((u[1:-1, 2:] - u[1:-1, 0:-2]) /
                         (2 * dx) + (v[2:, 1:-1] - v[0:-2, 1:-1]) / (2 * dy)) -
                        ((u[1:-1, 2:] - u[1:-1, 0:-2]) / (2 * dx))**2 -
                          2 * ((u[2:, 1:-1] - u[0:-2, 1:-1]) / (2 * dy) *
                               (v[1:-1, 2:] - v[1:-1, 0:-2]) / (2 * dx))-
                              ((v[2:, 1:-1] - v[0:-2, 1:-1]) / (2 * dy))**2))
       
    #$ omp end section
   
    #$ omp section
   
    # Calcul de p
        pn[:,:] = p[:,:]
   
        #$ omp for
        for q in range(nit):
            pn[:,:] = p[:,:]
            p[1:-1, 1:-1] = (((pn[1:-1, 2:] + pn[1:-1, 0:-2]) * dy**2 +
                                (pn[2:, 1:-1] + pn[0:-2, 1:-1]) * dx**2) /
                                (2 * (dx**2 + dy**2)) -
                                dx**2 * dy**2 / (2 * (dx**2 + dy**2)) *
                                b[1:-1,1:-1])

            p[:, -1] = p[:, -2] # dp/dx = 0 at x = 2
            p[0, :] = p[1, :]   # dp/dy = 0 at y = 0
            p[:, 0] = p[:, 1]   # dp/dx = 0 at x = 0
            p[-1, :] = 0        # p = 0 at y = 2
    #$ omp end section
   
    #$ omp section
        u[1:-1, 1:-1] = (un[1:-1, 1:-1]-
                         un[1:-1, 1:-1] * dt / dx *
                        (un[1:-1, 1:-1] - un[1:-1, 0:-2]) -
                         vn[1:-1, 1:-1] * dt / dy *
                        (un[1:-1, 1:-1] - un[0:-2, 1:-1]) -
                         dt / (2 * rho * dx) * (p[1:-1, 2:] - p[1:-1, 0:-2]) +
                         nu * (dt / dx**2 *
                        (un[1:-1, 2:] - 2 * un[1:-1, 1:-1] + un[1:-1, 0:-2]) +
                         dt / dy**2 *
                        (un[2:, 1:-1] - 2 * un[1:-1, 1:-1] + un[0:-2, 1:-1])))
   
        v[1:-1,1:-1] = (vn[1:-1, 1:-1] -
                        un[1:-1, 1:-1] * dt / dx *
                       (vn[1:-1, 1:-1] - vn[1:-1, 0:-2]) -
                        vn[1:-1, 1:-1] * dt / dy *
                       (vn[1:-1, 1:-1] - vn[0:-2, 1:-1]) -
                        dt / (2 * rho * dy) * (p[2:, 1:-1] - p[0:-2, 1:-1]) +
                        nu * (dt / dx**2 *
                       (vn[1:-1, 2:] - 2 * vn[1:-1, 1:-1] + vn[1:-1, 0:-2]) +
                        dt / dy**2 *
                       (vn[2:, 1:-1] - 2 * vn[1:-1, 1:-1] + vn[0:-2, 1:-1])))

        u[0, :]  = 0
        u[:, 0]  = 0
        u[:, -1] = 0
        u[-1, :] = 1    # set velocity on cavity lid equal to 1
        v[0, :]  = 0
        v[-1, :] = 0
        v[:, 0]  = 0
        v[:, -1] = 0
    #$ omp end section
    #$ omp end sections
    #$ omp end parallel
