function A = divvy (A,k)
    L = (mod(A,k) ~= 0);    % creates a logical matrix based on divisibility by k
    A(L) = k * A(L);        % changes only the non-divisible elements of A by multiplying them by k
end
% uses A as both input and output, so we only need to modify some elements of A