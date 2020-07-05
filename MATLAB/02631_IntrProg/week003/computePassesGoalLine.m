function score = computePassesGoalLine(point, directionVector)
% Returns true if a ball traveling from x,y coordinates in input
% point traveling in a straight line along input directionVector
% will pass the goal line in either of the two goals on a standard
% football field
 
% Constants for the football field
goalLeftX = 0;
goalRightX = 105;
goalLower = 30.34;
goalUpper = 37.66;
 
% Check if ball travels to the right or left. Ball crosses goal
% line at point + alpha * directionVector. Compute alpha.
if directionVector(1) > 0 
    % Ball travels right
    alpha = (goalRightX - point(1)) / directionVector(1);
else
    % Ball travels left
    alpha = (goalLeftX - point(1)) / directionVector(1);
end
 
% Compute y-coordinate where ball passes end of field
yGoal = point(2) + alpha * directionVector(2);
 
% Check if score in either of the two goals
score = yGoal > goalLower && yGoal < goalUpper;
end