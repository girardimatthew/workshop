function out = removechar(cv,str)
[row, col] = size(cv);
out = cell(row,col);
%str = 'the';
ii = 1;
jj = 1;
for rr = 1:row
    for cc = 1:col
        while ii <= (length(cv{rr,cc}) - 1)
            if cv{rr,cc}(ii) == str(1) && cv{rr,cc}(ii+1) == str(2) && cv{rr,cc}(ii+2) == str(3)
                out{rr,cc}(jj-1) = cv{rr,cc}(ii+3);
                ii = ii + 4;
                %out
            else
                out{rr,cc}(jj) = cv{rr,cc}(ii);
                ii = ii + 1;
                jj = jj + 1;
                %out
            end
        end
        out{rr,cc}(length(cv{rr,cc}) - (ii - jj)) = cv{rr,cc}(length(cv{rr,cc}));
        ii = 1;
        jj = 1;
    end
end
end