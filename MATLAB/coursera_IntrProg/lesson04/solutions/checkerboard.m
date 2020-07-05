function b = checkerboard(n,m)
b = ones(n,m);
b(1:2:n,2:2:m) = 0;
b(2:2:n,1:2:m) = 0;
end