function [tw, tv] = total_weight(vol, wd)
% tw = sum(vol .* wd); %array multiplication
tv = sum(vol);
tw = vol * wd'; % matrix multiplication
end