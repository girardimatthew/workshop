function out = censor(cv,str)
out = {};
[row, col] = size(cv);
ii = 1;
jj = 1;
for rr = 1:row
    for cc = 1:col
        if strfind(cv{rr,cc},str) > 0
            ;
        else
            out{ii,jj} = cv{rr,cc};
            jj = jj + 1;
        end
    end
end