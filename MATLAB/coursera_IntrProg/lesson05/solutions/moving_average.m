function a = moving_average(x)
    persistent xp;
    if isempty(xp)
        xp = x;                 % first time, the buffer simply contains x
    elseif length(xp) < 25
        xp(end+1) = x;          % while fewer than 25 elements, keep adding x to the buffer
    else
        xp = [xp(2:end),x];     % replace first (oldest) element by shifting to the left
    end                         % and inserting x at the end
    a = mean(xp);
end