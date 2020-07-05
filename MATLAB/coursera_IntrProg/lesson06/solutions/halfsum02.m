function s = halfsum(A)
    [nr,~] = size(A);
    s = 0;
    for r = 1:nr                    % for each row
        s = s + sum(A(r,r:end));    % sum adds up the elements right of the diagonal (inclusive)
    end                             % in the current row
end