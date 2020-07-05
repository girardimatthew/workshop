function out = movies(hr1,min1,durmin1,hr2,min2,durmin2)
min1end = 0;
hour = durmin1/60;
inthour = fix(hour);
if inthour ~= hour
    min = 60 * (hour - inthour);
    hr1end = hr1 + fix(hour);
    if min1 + min >= 60
        hr1end = hr1end + 1;
        min1end = min1end + ((min + min1) - 60);
    else
        min1end = min + min1;
    end
    %fprintf('1 - ore:%d min:%.2f\n', hr1end, min1end);
else
    hr1end = hr1 + hour;
    min1end = min1;
    %fprintf('2 - ore:%d min:%d\n', hr1end, min1end);
end

if hr1end == hr2
    if min1end <= min2 && (min2 - min1end) <= 30
        %fprintf('3 - ore:%d min:%.2f\n', hr1end, min1end);
        out = true;
    else
        out = false;
    end
elseif (hr2 - hr1end) == 1 || (hr2 - hr1) == 1
    gap = min1end + 30;
    if gap == 60
        hr1end = hr1end + 1;
        min1end = 0;
        if (hr1end == hr2) && (min1end == min2)
            out = true;
        else
            out = false;
        end
    elseif gap < 60 && min2 == 0
        min2 = 60;
        if (gap - min2) <= 30;
            out = true;
        else 
            out = false;
        end
    else
        out = false;
    end
elseif hr1end > hr2
    out = false;
end