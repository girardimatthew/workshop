function out = identity(n)
out = zeros(n);
out(1:n+1:n*n) = 1;
end