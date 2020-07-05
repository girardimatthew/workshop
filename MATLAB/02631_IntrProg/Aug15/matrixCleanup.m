function MClean = matrixCleanup(M)
%matrixCleanup
%   this function takes a matrix as input and returns the matrix 
%   where the rows and columns that contain one or 
%   more zero values have been removed.
%   
%   USAGE:
%   MClean = matrixCleanup(M)
%
%   INPUT
%   - M:                Input matrix
%
%   OUTPUT
%   - MClean:           Output matrix
%
[r c] = size(M);
rM = [];
for i = 1:r
    if sum(M(i,:)==0)==0
        rM = [rM; M(i,:)];
    end
end
MClean = [];
for i = 1:c
    if sum(M(:,i)==0)==0
        MClean = [MClean, rM(:,i)];
    end
end
end

%% Suggested solution
% function MClean = matrixCleanup(M)
%  
% % Rows to keep
% rowsKeep = ~any(M == 0, 2);
%  
% % Columns to keep
% colsKeep = ~any(M == 0, 1);
%  
% % Remove rows and columns from M
% M = M(rowsKeep, :);
% M = M(:, colsKeep);
%  
% % Return the cleaned matrix
% MClean = M;