function x = rand_int(n,m)
x = randi(10,n,m);
fprintf('The last element on the last row is %d\n', x(n,m));
end