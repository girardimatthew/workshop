%% Example 
% Change the value if it is greater than 0.1 with its
% square root.
% But with logical indexing, you can do it just with
% one line of code. Like this:
% A(A > 0.1) = sqrt(A(A > 0.1))

function M = square_root(A)
for ii = 1:length(A)
    for jj = 1:length(A)
        if A(ii,jj) > 0.1
            A(ii,jj) = sqrt(A(ii,jj));
        end
    end
end
M = A;
end

    