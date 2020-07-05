import math
import numpy as np
 
def acuteAngle(v1, v2):
    # Computes the acute angle between two lines represented by unit
    # vectors v1 and v2
 
    # Compute the angle (could be acute or obtuse)
    theta = math.acos(np.dot(v1, v2))
 
    # If angle is obtuse, compute the acute angle
    if theta > math.pi / 2:
        theta = math.pi - theta
 
    return theta