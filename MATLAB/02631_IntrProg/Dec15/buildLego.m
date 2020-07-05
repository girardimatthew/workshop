function bricks = buildLego(h, l, w)
%buildLego
%   this function takes as input the height h, width w, and length l of a 
%   lego brick and computes the maximum number of lego bricks that 
%   can be used for your tower if the volume can not exceed 1000cm^3
%   
%   USAGE:
%   bricks = buildLego(h, l, w)
%
%   INPUT
%   - h:                Height of the lego brick (positive decimal number)
%   - l:                Length of the lego brick (positive decimal number)
%   - w:                Width of the lego brick (positive decimal number)
%
%   OUTPUT
%   - bricks:           Number of lego bricks (integer)
%
maxV = 1001;
bricks = 1;
V = h*l*w;
iV = V;
while V < maxV
    V = V + iV;
    bricks = bricks + 1;
end
bricks = bricks - 1;
end

% % function bricks = buildLego(h,l,w)
% %  
% % % Calculate volume
% % V = h*l*w;
% %  
% % % Calculate number of bricks
% % bricks = floor(1000/V);