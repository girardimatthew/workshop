function averageM = averagedB(M)
%convertGrade
%   this function takes a matrix as input, removes rows that contain 
%   values above 70 dB, and returns a vector containing the average 
%   of each column for the reduced matrix.
%   
%   USAGE:
%   averageM = averagedB(M)
%
%   INPUT
%   - M:                Input matrix
%
%   OUTPUT
%   - averageM:         Output vector
%
[r c] = size(M);
nM = [];
for i = 1:r
    if sum(M(i,:)>70)==0
        nM = [nM; M(i,:)];
    end
end
averageM = mean(nM,1);
end

% % function averageM = averagedB(M)
% %  
% % % Find rows that contain values above 70
% % [row, col] = find(M>70);
% %  
% % % Remove the located rows
% % M(row,:) = [];
% %  
% % % Calculate average of columns
% % averageM = mean(M,1);
