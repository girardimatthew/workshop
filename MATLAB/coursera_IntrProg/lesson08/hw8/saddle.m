function indices = saddle(M)
indices = [];
indx_max_row_val = [];
[rowM, colM] = size(M);
len = rowM.*colM;
if 1 && ~any(M(:))
    l = 1;
    c = 1;
    while l <= len
        for r = 1:rowM
            indices(l,1) = r; 
            indices(l,2) = c;
            l = l + 1;
        end 
        c = c + 1;
    end  
    return;
end
r = 1;
ncc = 1;
for rr = 1:rowM
    for cc = 1:colM
        if M(rr,ncc) > M(rr,cc)
            indx_max_row_val(r,1) = rr;
            indx_max_row_val(r,2) = ncc;
        else
            indx_max_row_val(r,1) = rr;
            indx_max_row_val(r,2) = cc;
            ncc = cc;
        end
        indx_max_row_val;
    end
    r = r + 1;
end
indices = indx_max_row_val;
        
end





% function indices = saddle(M)
% indices = [];
% [row, col] = size(M);
% len = row.*col;
% ir = 1;
% if 1 && ~any(M(:))
%     l = 1;
%     c = 1;
%     while l <= len
%         for r = 1:row
%             indices(l,1) = r; 
%             indices(l,2) = c;
%             l = l + 1;
%         end 
%         c = c + 1;
%     end  
%     return;
% end
% for rr = 1:row
%     [~, c] = max(M(rr,:));
%     %fprintf('row: %d max: %d ', rr, c);
%     [~, r] = min(M(:,c));
%     %fprintf('min: %d', r);
%     %fprintf('\n');
%     if max(M(rr,:)) == min(M(:,c))
%         indices(ir,1) = r;
%         indices(ir,2) = c;
%         ir = ir + 1 ;
%     end
% end
% end
