function out = June2015
    c = cell(30,3);
    day{1} = 'Mon';
    day{2} = 'Tue';
    day{3} = 'Wed';
    day{4} = 'Thu';
    day{5} = 'Fri';
    day{6} = 'Sat';
    day{7} = 'Sun';
    n = 1;
    for rr = 1:30
        c{rr,1} = 'June';
        for cc = 2:3
            if cc == 2
                c{rr,cc} = rr;
            else
                c{rr,cc} = day{n};
                n = n + 1;
                if n == 8
                    n = 1;
                end
            end        
    end
    out = c;
end