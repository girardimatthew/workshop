function name = weekday(d, m, y)
%weekday
%   this function takes as input the date, month, and year 
%   numbers and returns the weekday name as a string
%   
%   USAGE:
%   name = weekday(d, m, y)
%
%   INPUT
%   - d:        Date number (integer, 1 . . . 31)
%   - m:        Month number (integer, 1 . . . 12)
%   - y:        Year number (integer, 0 . . . 99)
%
%   OUTPUT
%   - name:     Name of the weekday (string)
%
if (d<1 || d>31) || (m<1 || m>12) || (y<0 || y>99)
    name = 'NULL';
    fprintf(2,'WARNING: invalid input data\n');
    return;
end
monthCode = [6 2 2 5 0 3 5 1 4 6 2 4];
C = monthCode(m);
w = mod((d + C + y + floor(y/4)),7);
switch w
    case 0
        name = 'Sun';
    case 1
        name = 'Mon';
    case 2
        name = 'Tue';
    case 3
        name = 'Wed';
    case 4
        name = 'Thu';
    case 5
        name = 'Fri';
    case 6
        name = 'Sat';
    otherwise
        name = 'NULL';
end
end