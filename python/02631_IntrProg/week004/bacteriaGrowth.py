def bacteriaGrowth(n0, alpha, K, N):
    # Computes the number of hours before a population of bacteria
    # growing according to n(t+1) = (1 + alpha * (1-n(t)/K)) * n(t)
    # exceeds N, starting with n0 bacteria at time t=0
 
    # Current time step
    t = 0
     
    # Population size
    nt = n0
     
    # Repeat while population does not exceed N
    while (nt <= N):
        nt = (1 + alpha*(1 - nt/K)) * nt
        t = t + 1
     
    # Return final time
    return t