import math
import numpy as np
 
def computeProjection(a):
    # Create b as vector of all ones with same length as input a
    b = np.ones(np.size(a))
 
    # Compute squared magnitude of a
    squared_magnitude_a = sum(a**2)
 
    # Compute projection
    projection = np.dot(a,b) / squared_magnitude_a * a
    return projection