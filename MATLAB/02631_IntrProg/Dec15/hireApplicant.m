function applicantZone = hireApplicant(skill, pay)
%convertGrade
%   this function that takes the skill and pay 
%   as numeric input and returns the applicantZone as a string
%   
%   USAGE:
%   applicantZone = hireApplicant(skill, pay)
%
%   INPUT
%   - skill:            Skill given on a scale from 0 to 10 (decimal number)
%   - pay:              Pay given on a scale from 1 to 10 (decimal number).
%
%   OUTPUT
%   - applicantZone:    Applicant zone (string)
%
Zone = {'No go', 'Too expensive', 'Hire', 'Long term contract', 'Unicorn'};
f = 0.9*skill + 1;
if skill<5
    applicantZone = char(Zone(1));
elseif skill>=5 && pay>f
    applicantZone = char(Zone(2));
elseif skill>=5 && skill<8 && pay<= f
    applicantZone = char(Zone(3));
elseif skill>=8 && pay>4 && pay<=f
    applicantZone = char(Zone(4));
elseif skill>=8 && pay<=4
    applicantZone = char(Zone(5));
else
    applicantZone = 'NULL';
end
end