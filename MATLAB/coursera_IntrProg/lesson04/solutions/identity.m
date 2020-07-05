function I = identity(n)
    I = zeros(n);
    I(1 : n+1 : n^2) = 1;
end