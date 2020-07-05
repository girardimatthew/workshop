-- myHead

myHead (x:xs) = x
myHead [] = error "No head for empty list."