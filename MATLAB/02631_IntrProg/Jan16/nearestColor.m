function colorName = nearestColor(r, g, b)
%nearestColor
%   this function takes a value of r, g, and b as input and returns the 
%   name of the nearest color as a string (written exactly as in the table above.) 
%   The nearest color is defined as the color in the table to which 
%   the distance is smallest. If two or more colors in the table have 
%   the same smallest distance, the name of the color which occurs 
%   first in the table must be returned.
%
%   USAGE:
%   colorName = nearestColor(r, g, b)
%
%   INPUT
%   - r,g,b:                    Value of r, g, and b (decimal number)
%
%   OUTPUT
%   - colorName:                Name of nearest color (string).
%

colorNames = {'White', 'Grey', 'Black', 'Red', 'Maroon', 'Yellow', 'Olive',...
    'Lime', 'Green', 'Aqua', 'Teal', 'Blue', 'Navy', 'Fuchsia', 'Purple'};
C = [100 50 0 100 50 100 50 0 0 0 0 0 0 100 50;... 
    100 50 0 0 0 100 50 100 50 100 50 0 0 0 0;...
    100 50 0 0 0 0 0 0 0 100 50 100 50 100 50];
L = length(C);
RGB = [r,g,b];
D = [];
for k = 1:L
   D = [D, max(abs(RGB'-C(:,k)))];
end 
[~, indx] = min(D);
colorName = colorNames{indx};

end

% % % Define color names
% % colorNames = {'White', 'Grey', 'Black', 'Red', 'Maroon', 'Yellow', 'Olive', ...
% %     'Lime', 'Green', 'Aqua', 'Teal', 'Blue', 'Navy', 'Fuchsia', 'Purple'};
% %      
% % % Define color rgb-values
% % R = [100, 50, 0, 100, 50, 100, 50, 0, 0, 0, 0, 0, 0, 100, 50];
% % G = [100, 50, 0, 0, 0, 100, 50, 100, 50, 100, 50, 0, 0, 0, 0];
% % B = [100, 50, 0, 0, 0, 0, 0, 0, 0, 100, 50, 100, 50, 100, 50];
% %  
% % % Compute distance to each color
% % D = max([abs(R-r); abs(G-g); abs(B-b)]);
% %  
% % % Find nearest color
% % [~, colorIndex] = min(D);
% %  
% % % Get color name
% % colorName = colorNames{colorIndex};