function out =  replace(cv,c1,c2)
    [row, col] = size(cv);
    out = cell(row,col);
    for rr = 1:row
        for cc = 1:col
            for nn = 1:length(cv{rr,cc})
                %fprintf('%d,%d,%d,%d\n',rr,cc,rr,nn);
                if cv{rr,cc}(rr,nn) == c1
                    out{rr,cc}(rr,nn) = c2;
                    
                else
                    out{rr,cc}(rr,nn) = cv{rr,cc}(rr,nn);
                end
            end
        end
    end
end