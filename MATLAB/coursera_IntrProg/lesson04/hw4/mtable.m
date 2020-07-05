function [mt,s] = mtable(n,m)
v = (1:1:n)';
mt = v(:)*(1:m);
s = sum(sum(mt));
end