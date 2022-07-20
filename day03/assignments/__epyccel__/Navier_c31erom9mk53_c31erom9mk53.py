
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



