function [t, s] = mtable(n,m)
    t = (1:n)' * (1:m);
    s = sum(t(:));
end