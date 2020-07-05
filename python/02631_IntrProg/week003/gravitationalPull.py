import numpy as np
 
def gravitationalPull(x):
    # Computes the gravitational pull in meters per second squared at a
    # distance x to the center of the earth
 
    # Gravitational pull at surface
    g0 = 9.82
    # Radius of earth
    R = 6.371e6
    # Compute gravitational pull
    if x < R:
        g = g0 * x / R
    else:
        g = g0 * R**2 / x**2
    return g
 
    # # Solution that works for vector input (but not for scalar input)
    # # Make empty vector to store result
    # g = np.zeros(np.size(x))
    # # Compute gravitational pull for x < R
    # g[x < R] = g0 * x[x < R] / R
    # # Compute gravitational pull for x >= R
    # g[x >= R] = g0 * R**2 / x[x >= R]**2