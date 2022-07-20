
import numpy as np

def build_up_b_numba(b:'float[:,:]', rho:'int', dt:'float', u:'float[:,:]', v:'float[:,:]', dx:'float', dy:'float'):
    #fill the update of b
   
    b[1:-1, 1:-1] = (rho * (1 / dt *     
                    ((u[1:-1, 2:] - u[1:-1, 0:-2]) / (2 * dx) +   
                    (v[2:, 1:-1] - v[0:-2, 1:-1]) / (2 * dy)) -    
                    ((u[1:-1, 2:] - u[1:-1, 0:-2]) / (2 * dx))**2 -  
                      2 * ((u[2:, 1:-1] - u[0:-2, 1:-1]) / (2 * dy) *  
                           (v[1:-1, 2:] - v[1:-1, 0:-2]) / (2 * dx))-
                          ((v[2:, 1:-1] - v[0:-2, 1:-1]) / (2 * dy))**2))
    return 0


def pressure_poisson_numba(p:'float[:,:]', dx:'float', dy:'float', b:'float[:,:]',nit:'int'):
    pn = np.empty_like(p)
    #fill the update of p
    for m in range(nit):
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
    
    return 0 


def cavity_flow_numba(nt:'int', u:'float[:,:]', v:'float[:,:]', dt:'float', nx:'int', ny:'int', dx:'float', dy:'float', p:'float[:,:]', rho:'int', nu:'float'):
    un = np.empty_like(u)
    vn = np.empty_like(v)
    b = np.zeros((ny, nx))
    
    #fill the update of u and v
    for n in range(nt):
        un[:,:] = u[:,:]
        vn[:,:] = v[:,:]    
        build_up_b_numba(b, rho, dt, u, v, dx, dy)
        pressure_poisson_numba(p, dx, dy, b)
        
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
    return 0

