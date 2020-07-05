-- add3ToAll

add3ToAll [] = []
add3ToAll (x:xs) = (3 + x):add3ToAll xs