function index = matrixSearch(A, x)
[M, N] = size(A);
index = [0, 0];
i = 1;
j = N;
while j>0 && i<=M
    if A(i,j) == x
        index = [i,j];
        break;
    elseif A(i,j) > x
        j = j - 1;
    elseif A(i,j) < x
        i = i + 1;
    else
    end
end
end

%% Suggested solution
% function index = matrixSearch(A, x)
%  
% % Matrix dimensions
% [M, N] = size(A);
%  
% % Initial position
% i = 1;
% j = N;
%  
% % Continue while we have not found x
% while A(i,j) ~= x
%    if A(i,j) > x
%       % Move left
%       j = j - 1;
%    else
%       % Move down
%       i = i + 1;
%    end
%    % Check if we are outside matrix
%    if i > M || j < 1
%       i = 0;
%       j = 0;
%       break;
%    end
% end
%  
% % Collect i and j in vector
% index = [i j];