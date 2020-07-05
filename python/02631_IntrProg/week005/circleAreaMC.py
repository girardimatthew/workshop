import numpy as np
 
def circleAreaMC(xvals, yvals):
    # Estimates the area of a circle using Monte carlo estimation
 
    # Compute the number of points
    N = np.size(xvals)
 
    # Compute distance from each point to (0,0)
    dist = np.sqrt(xvals**2 + yvals**2)
 
    # Count number of points inside the circle
    n = np.sum(dist < 1)
 
    # Compute area of circle
    A = 4.0 * n / N
    return A