function ECTSGrade = convertGrade(grade, scale)
%convertGrade
%   this function takes a grade given in the 7-point or 13-scale as 
%   numeric input (use the numbers in brackets) and the scale 
%   (7-point or 13-scale) as a string, and returns the grade 
%   converted to the ECTS scale as a string
%   
%   USAGE:
%   ECTSGrade = convertGrade(grade, scale)
%
%   INPUT
%   - grade:                Grade given on the 7-point scale or 13-scale (whole number)
%   - scale:                Scale to convert from (string): either ?13-scale? or ?7-point?
%
%   OUTPUT
%   - ECTSGrade:            Grade on the ECTS scale (string)
%
oldSys = '13-scale';
newSys = '7-point';

if strcmpi(scale,oldSys)
    switch grade
        case 13
            ECTSGrade = 'A';
        case 11
            ECTSGrade = 'A';
        case 10
            ECTSGrade = 'B';
        case 9 
            ECTSGrade = 'C';
        case 8
            ECTSGrade = 'C';
        case 7
            ECTSGrade = 'D';
        case 6
            ECTSGrade = 'E';
        case 5
            ECTSGrade = 'Fx';
        case 03
            ECTSGrade = 'Fx';
        case 00
            ECTSGrade = 'F';
        otherwise
            fprintf(2,'Error: Invalid grade!\n');
            ECTSGrade = 'NULL';
    end
elseif strcmpi(scale,newSys)
    switch grade
        case 12
            ECTSGrade = 'A';
        case 10
            ECTSGrade = 'B';
        case 7
            ECTSGrade = 'C';
        case 4
            ECTSGrade = 'D';
        case 02
            ECTSGrade = 'E';
        case 00
            ECTSGrade = 'Fx';
        case -3
            ECTSGrade = 'F';
        otherwise
            fprintf(2,'Error: Invalid grade!\n');
            ECTSGrade = 'NULL';
    end
else
    fprintf(2,'Error: Invalid scale!\n');
    ECTSGrade = 'NULL';
end

end