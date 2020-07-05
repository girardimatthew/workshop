import numpy as np
 
def clusterAnalysis(reflectance):
    # Clusters reflectance measurements into two groups and returns
    # the cluster assignments
 
    # Number of measurements
    N = np.size(reflectance)
 
    # Initialize cluster assignments
    clusterAssignments = (np.arange(0, N) % 2) + 1
 
    # Variable for old cluster assignments
    oldClusterAssignments = np.zeros(N)
 
    # Repeat until cluster assignments do not change
    while not np.all(clusterAssignments == oldClusterAssignments):
        # Save the old cluster assignments
        oldClusterAssignments = np.copy(clusterAssignments)
     
        # Compute mean values
        m1 = np.mean(reflectance[clusterAssignments == 1])
        m2 = np.mean(reflectance[clusterAssignments == 2])
     
        # Loop over all measurements
        for i in range(N):
            # Compute distance to means
            d1 = abs(reflectance[i] - m1)
            d2 = abs(reflectance[i] - m2)
             
            # Update cluster assignments
            if d1 <= d2:
                clusterAssignments[i] = 1
            else:
                clusterAssignments[i] = 2
         
    return clusterAssignments