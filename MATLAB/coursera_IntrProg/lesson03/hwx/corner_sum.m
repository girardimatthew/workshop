function s = corner_sum(A)
%[m,n] = size(A);
%s = A(1,1) + A(1,n) + A(m,1) + A(m,n);
s = A(1,1) + A(1,end) + A(end,1) + A(end,end);
%Do not delete the ending semicolon
%doing that will cause the result to be printed
%directly to the Command Window