function check = sudokuCheck(sudokuBoard)
%sudokuCheck
%   this function takes as input a 9-by-9 matrix, sudokuBoard, 
%   and checks whether the sum of each row, each column, 
%   and each 3-by-3 block is 45. The function must output the 
%   variable check that contains the overall number of rows, 
%   columns, and blocks that do not sum to 45.
%   
%   USAGE:
%   check = sudokuCheck(sudokuBoard)
%
%   INPUT
%   - sudokuBoard:      9-by-9 matrix (numbers from 1 to 9)
%
%   OUTPUT
%   - check:            Result from check (integer)
%
check = 0;
c = sum(sudokuBoard,1);
r = sum(sudokuBoard,2);
check = check + sum(c~=45);
check = check + sum(r~=45);
R = [1:3];
C = [1:3];
for i = 1:9
    if i == 4
        R = R + 3;
        C = [1:3];
    elseif i == 7
        R = R + 3;
        C = [1:3];
    end
    if sum(sum(sudokuBoard(R,C)))~=45
        check = check + 1;
    end
    C = C + 3;
end
end

% % function check = sudokuCheck(sudokuBoard)
% %  
% % % Sum of columns and rows
% % sumCol = sum(sudokuBoard,1);
% % sumRow = sum(sudokuBoard,2);
% %  
% % % Sum of blocks
% % sumBlock = zeros(3,3);
% % for i = 1:3
% %     for j = 1:3
% %         sumBlock(i,j) = sum(sum(sudokuBoard(1+3*(i-1):3+3*(i-1),1+3*(j-1):3+3*(j-1))));
% %     end
% % end
% %  
% % % Calculate number of errors
% % check = sum([sumRow; sumCol'; sumBlock(:)]~=45);