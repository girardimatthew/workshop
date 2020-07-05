-- myReverse

rcons x y = y:x
myReverse xs = foldl rcons [] xs