function shirtSize = computeShirtSize(chest, waist)
%computeShirtSize
%   this function returns the shirt size as a string
%   such that the given chest and waist measurement are both within 
%   the given ranges. Note that the measurement ranges overlap: 
%   If the given chest and waist measurements fit more than one shirt size, 
%   the function must return the smallest size that fits. 
%   If the given chest and waist measurements do not fit 
%   any of the given shirt sizes, the string Not available must be returned.
%
%   USAGE:
%   shirtSize = computeShirtSize(chest, waist)
%
%   INPUT
%   - chest:            Chest measurement (decimal number)
%   - waist:            Waist measurement (decimal number)
%
%   OUTPUT
%   - shirtSize:        shirtSize
%
Size = {'Small','Medium','Large','X-Large','XX-Large','Not available'};
if chest>=38 && chest<=42 && waist>=30 && waist<=35
    shirtSize = Size{1};
elseif chest>=40 && chest<=44 && waist>=32 && waist<=37
    shirtSize = Size{2};
elseif chest>=42 && chest<=46 && waist>=34 && waist<=39
    shirtSize = Size{3};
elseif chest>=44 && chest<=48 && waist>=36 && waist<=41
    shirtSize = Size{4};
elseif chest>=46 && chest<=50 && waist>=38 && waist<=43
    shirtSize = Size{5};
else
    shirtSize = Size{6};
end
end

% % function shirtSize = computeShirtSize(chest, waist)
% %  
% % % Define ranges
% % chestMin = [38 40 42 44 46];
% % chestMax = [42 44 46 48 50];
% % waistMin = [30 32 34 36 38];
% % waistMax = [35 37 39 41 43];
% %  
% % % Define shirt sizes 
% % shirtSizes = {'Small', 'Medium', 'Large', 'X-Large', 'XX-Large'};
% % notAvailable = 'Not available';
% %  
% % % Find compatible sizes
% % chestCompatible = (chest >= chestMin) & (chest <= chestMax);
% % waistCompatible = (waist >= waistMin) & (waist <= waistMax);
% % compatible = chestCompatible & waistCompatible;
% %  
% % % If no compatible shirts, return Not available
% % if ~any(compatible)
% %     shirtSize = notAvailable;
% %  
% % % Choose smallest compatible shirt size
% % else
% %     shirtIndex = find(compatible, 1);
% %     shirtSize = shirtSizes{shirtIndex};
% % end