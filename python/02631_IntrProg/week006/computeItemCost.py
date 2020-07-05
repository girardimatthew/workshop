import numpy as np
 
def computeItemCost(resourceItemMatrix, resourceCost):
    # Compute the cost of each item using a vector-matrix product
    itemCost = np.dot(resourceCost, resourceItemMatrix)
    return itemCost