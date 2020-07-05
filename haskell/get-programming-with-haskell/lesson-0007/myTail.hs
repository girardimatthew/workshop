-- myTail

myTail (_:xs) = xs
myTail [] = error "No tail for empty list."