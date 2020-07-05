function out = halfsum(A)
    [row, col] = size(A);
    out = 0;
    for rr = 1:row
        for cc = rr:col
            out = out + A(rr,cc);
        end
    end
end


% function r = halfsum(A)
%     r = sum(sum(triu(A)));
% end

% function out = halfsum(A)
% [row,col] = size(A);
% out = 0;
% for rr = 1:row
%     for cc = rr:col
%         out = out + A(rr,cc);
%     end
% end
% end

% WHY???
% A =
%      3     5     4     3     6
%      2     2     4     4     1
%      3     8     7     4    10
%      5     7     5     5     3
%      4     9     2    10     5
% A(1,1):A(1,5)
% ans =
%      3     4     5     6
% A(1,1):A(1,5)
% ans =
%      3     4     5     6
% B = [1 2 3 4 5; 6 7 8 9 10]
% B =
%      1     2     3     4     5
%      6     7     8     9    10
% B(1,1):B(1,5)
% ans =
%      1     2     3     4     5
% B(1,:)
% ans =
%      1     2     3     4     5
% A(1,:)
% ans =
%      3     5     4     3     6
% A(1,1):A(1,5)
% ans =
%      3     4     5     6
