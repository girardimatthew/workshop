function idComplete = removeIncomplete(id)
% INPUT: id Id-numbers (vector of decimal numbers)
% OUTPUT: idComplete Id-numbers of complete experiments (vector of decimal numbers)
% USAGE: removeIncomplete(id)
SrtID = sort(id);
nExp = floor(max(SrtID));
nPart = 3;
mtrx = ones(nExp,1)*[((1:3)/10)] + [1:nExp]'*ones(1,3);
i=1;
v = [];
for r = 1:nExp
    for c = 1:nPart
        if mtrx(r,c) == SrtID(i)
            i = i + 1;
        elseif mtrx(r,c) ~= SrtID(i);
            v = [v, r];
        end
    end
end
v = unique(v);
for m = 1:length(v)
    id(floor(id) == v(m)) = 0;
end
idComplete = id(id~=0);
end

%% solution
% function idComplete = removeIncomplete(id)
%  
% % Indices of id-numbers that will be retained
% completeIds = true(size(id));
%  
% % Loop over all id-numbers
% for i = 1:length(id)
%     % Current experiment-number
%     experimentNumber = floor(id(i));
%      
%     % Count number of parts with current experiment-number
%     numberOfParts = sum(floor(id) == experimentNumber);
%  
%     % Mark id-number as incomplete if there are not 3 parts
%     if numberOfParts ~= 3
%         completeIds(i) = false;
%     end
% end
%  
% % Remove incomplete id-numbers
% idComplete = id(completeIds);