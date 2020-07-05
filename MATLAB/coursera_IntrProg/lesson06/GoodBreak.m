found = false;
for ii = 1:size(A,1)
    for jj = 1:size(A,2)
        if A(ii,jj) <= 90
            A(ii,jj) = 0;
        else
            found = true;
            break;
        end
    end
    % same instruction. they are equal
    % if found 
    if found == true
        break;
    end
end
