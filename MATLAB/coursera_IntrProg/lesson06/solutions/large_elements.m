function found = large_elements(A)
    [row col] = size(A);
    found = [];
    for ii = 1:row
        for jj = 1:col
            if A(ii,jj) > ii + jj       % if the element is larger than the sum of its indexes
                found = [found; ii jj]; % add a new row to the output matrix
            end
        end
    end
end