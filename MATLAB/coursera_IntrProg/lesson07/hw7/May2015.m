function out = May2015
strct.month = [];
strct.date = [];
strct.day = [];
day{1} = 'Fri';
day{2} = 'Sat';
day{3} = 'Sun';
day{4} = 'Mon';
day{5} = 'Tue';
day{6} = 'Wed';
day{7} = 'Thu';
n = 1;
    for ii = 1:31 
        strct(ii).month = 'May';
        strct(ii).date = ii;
        strct(ii).day = day{n};
        n = n + 1;
        if n == 8
            n = 1;
        end
    end
out = strct;
end