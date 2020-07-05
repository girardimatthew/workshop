function O = odd_index(M)
[r, c] = size(M);
O = M([1:2:r],[1:2:c]);
end