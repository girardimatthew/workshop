function ageGroup = computeAgeGroup(age)
%computeAgeGroup
%   this function takes the age as a numeric input and 
%   returns the age group as a string
%
%   USAGE:
%   ageGroup = computeAgeGroup(age)
%
%   INPUT
%   - age:          Age in years (decimal number).
%
%   OUTPUT
%   - ageGroup:     Age group (string)
%
group = {'Infant','Toddler','Child','Teenager','Adult'};
if age<1
    ageGroup = group{1};
elseif age<3
    ageGroup = group{2};
elseif age<13
    ageGroup = group{3};
elseif age<20
    ageGroup = group{4};
else
    ageGroup = group{5};
end
end