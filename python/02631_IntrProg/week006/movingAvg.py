import numpy as np
 
def movingAvg(y):
    # Returns the 5-sample symmetric weighted moving average of the
    # input vector, computed as
    # ysmooth(i) = (y(i-2) + 2*y(i-1) + 3*y(i) + 2*y(i+1) + y(i+2)) / 9
 
    # Length of input vector
    N = len(y)
     
    # Weights
    w = np.array([1, 2, 3, 2, 1])
 
    # Signal matrix with two extra columns at beginning and end
    M = np.zeros([5, N + 4])
 
    # Fill in rows with weighted signal
    for i in range(5):
        M[i, i:(N+i)] = w[i] * y
 
    # Cut the two extra columns at beginning and end
    M = M[:, 2:(N+2)]
 
    # Compute moving average
    ysmooth = np.sum(M, axis=0) / 9
    return ysmooth