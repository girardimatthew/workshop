function [reven, rodd] = separate_by_two(A)
    reven = A(mod(A,2) == 0)';
    rodd = A(mod(A,2) == 1)';
end