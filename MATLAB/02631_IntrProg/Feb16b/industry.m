function industryName = industry(industryCode)
%industry
%   this function takes as input a text string representing an industry 
%   code and returns the corresponding industry name as a text string 
%   The input consists of 4 characters which can be either digits (0?9) 
%   or the letter x. The x works as a ?wild card? that can stand for any digit. 
%   You can assume that the given code always matches exactly one of the code ranges in the table.
%   
%   USAGE:
%   industryName = industry(industryCode)
%
%   INPUT
%   - industrycode:
%
%   OUTPUT
%   - industryName:
%
idx = industryCode == 'x';
industryCode(idx) = '5';
N = str2double(industryCode);
if N>=0000 && N<=0999
    industryName = 'Agriculture';
elseif N>=1000 && N<=1499
    industryName = 'Mining';
elseif N>=1500 && N<=1999
    industryName = 'Construction';
elseif N>=2000 && N<=3999
    industryName = 'Manufacturing';
elseif N>=4000 && N<=4999
    industryName = 'Transportation';
elseif N>=5000 && N<=5999
    industryName = 'Trade';
elseif N>=6000 && N<=6999
    industryName = 'Finance';
elseif N>=7000 && N<=8999
    industryName = 'Services';
elseif N>=9000 && N<=9999
    industryName = 'Public';
else
    industryName = 'Unknown';
end
% % % Match the code number to the industry name
% % if code < 1000
% %     industryName = 'Agriculture';
% % elseif code < 1500
% %     industryName = 'Mining';
% % elseif code < 2000
% %     industryName = 'Construction';
% % elseif code < 4000
% %     industryName = 'Manufacturing';
% % elseif code < 5000
% %     industryName = 'Transportation';
% % elseif code < 6000
% %     industryName = 'Trade';
% % elseif code < 7000
% %     industryName = 'Finance';
% % elseif code < 9000
% %     industryName = 'Services';
% % else
% %     industryName = 'Public';
% % end
end