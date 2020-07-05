def boxArea(boxCorners, area):
     
    # Extract coordinates
    x1 = boxCorners[0]
    x2 = boxCorners[1]
    x3 = boxCorners[2]
    x4 = boxCorners[3]
    y1 = boxCorners[4]
    y2 = boxCorners[5]
    y3 = boxCorners[6]
    y4 = boxCorners[7]
     
    # Compute area of box 1
    A1 = (x2-x1)*(y2-y1)
     
    # Compute area of box 2
    A2 = (x4-x3)*(y4-y3)
     
    # Compute area of overlap
    Ao = max(0, min(x2,x4)-max(x1,x3)) * max(0, min(y2,y4)-max(y1,y3))
     
    if area == "Box1":
        A = A1
    elif area == "Box2":
        A = A2
    elif area == "Intersection":
        A = Ao
    elif area == "Union":
        A = A1 + A2 - Ao       
     
    return A