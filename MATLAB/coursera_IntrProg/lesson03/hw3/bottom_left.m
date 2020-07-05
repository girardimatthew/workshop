function out = bottom_left(N, n)
[r c] = size(N);
y = r - n + 1;
out = [N(y:r,1:n)];
end