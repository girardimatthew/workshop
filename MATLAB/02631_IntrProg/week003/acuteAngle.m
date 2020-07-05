function theta = acuteAngle(v1, v2)
% Computes the acute angle between two lines represented by unit
% vectors v1 and v2

% Compute the angle (could be acute or obtuse)
theta = acos(dot(v1,v2));

% If angle is obtuse, compute the acute angle
if theta > (pi/2)
    theta = pi - theta;
end
end
