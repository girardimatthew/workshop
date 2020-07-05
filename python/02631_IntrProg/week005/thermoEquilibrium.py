import numpy as np
 
def thermoEquilibrium(N, r):
    # Initial number of particles in left and right chamber
    NLeft = N
    NRight = 0
 
    # Time step
    t = 0
 
    # Number of random numbers
    NRand = np.size(r)
 
    # Repeat until chambers have equal number of particles
    while (NLeft != NRight):
        # Increment time
        t = t + 1
         
        # Stop if there are no more random numbers
        if (t > NRand):
            t = 0
            break
     
        # Probability of moving a particle from left to right
        pLR = NLeft / N
     
        # Randomly move a particle
        if (r[t-1] <= pLR):
            # Move one particle from left to right
            NLeft = NLeft - 1
            NRight = NRight + 1
        else:
            # Move one particle from right to left
            NLeft = NLeft + 1
            NRight = NRight - 1
 
    return t