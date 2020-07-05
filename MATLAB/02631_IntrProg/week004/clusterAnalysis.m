function clusterAssignments = clusterAnalysis(setR)
% DESCRIPTION: compute a clutering algorithm (k-means)
% INPUT: Reflectance measurements (vector of decimal numbers)
% OUTPUT: clusterAssignments Final cluster assignments (vector of numbers, 1 or 2)

% INIT vector of cluster assignments
clusterAssignments = zeros(1,length(setR));
% INIT clusters with odd and even index 
idx = 1:length(setR);
cl1 = setR(mod(idx,2)==1);
cl2 = setR(mod(idx,2)==0);
% SET label 
label = true;

% START algorithm
while label
    % FIND the mean of each cluster
    mean1 = mean(cl1);
    mean2 = mean(cl2);
    % FIND distance to the mean
    dist1 = abs(setR-mean1);
    dist2 = abs(setR-mean2);
    % INIT new empty clusters
    ncl1 = [];
    ncl2 = [];
    % ASSIGN values to new clusters
    for i = 1:length(setR)
        if dist1(i) <= dist2(i)
            ncl1 = [ncl1, setR(i)];
        else
            ncl2 = [ncl2, setR(i)];
        end
    end
    % STOP if the old cluster and new cluster are equal
    if (length(cl1) == length(ncl1) || length(cl2) == length(ncl2)) && (isequal(cl1,ncl1) || isequal(cl2,ncl2))
        label = false;
    end
    % UPDATE old cluster to new ones
    cl1 = ncl1;
    cl2 = ncl2;
end
% FIND indexes
indx1 = ismember(setR,cl1);
indx2 = ismember(setR,cl2);
% SET clusterAssignments accordingly
clusterAssignments(indx1) = 1;
clusterAssignments(indx2) = 2;
end

%% SUGGESTED SOLUTION
% function clusterAssignments = clusterAnalysis(reflectance)
% % Clusters reflectance measurements into two groups and returns
% % the cluster assignments
%  
% % Number of measurements
% N = length(reflectance);
%  
% % Initialize cluster assignments
% clusterAssignments = mod(0:N-1, 2) + 1;
%  
% % Variable for old cluster assignments
% oldClusterAssignments = zeros(1, N);
%  
% % Repeat until cluster assignments do not change
% while ~all(clusterAssignments == oldClusterAssignments)
%     % Save the old cluster assignments
%     oldClusterAssignments = clusterAssignments;
%      
%     % Compute mean values
%     m1 = mean(reflectance(clusterAssignments == 1));
%     m2 = mean(reflectance(clusterAssignments == 2));
%      
%     % Loop over all measurements
%     for i = 1:N
%         % Compute distance to means
%         d1 = abs(reflectance(i) - m1);
%         d2 = abs(reflectance(i) - m2);
%          
%         % Update cluster assignments
%         if d1 <= d2
%             clusterAssignments(i) = 1;
%         else
%             clusterAssignments(i) = 2;
%         end
%     end
% end