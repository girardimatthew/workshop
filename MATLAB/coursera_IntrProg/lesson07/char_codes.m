function char_codes
for ii = 33:126
    fprintf('%d:%s\n',ii,char(ii));
    %fprintf('%s',char(ii));
    % fprintf('%s\n',char(ii));
end
fprintf('\n');