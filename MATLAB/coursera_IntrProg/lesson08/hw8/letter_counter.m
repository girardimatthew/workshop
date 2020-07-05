function output = letter_counter(filename)
fid = fopen(filename,'rt');
if fid < 0
    output = -1;
    return;
end
output = 0;
oneline = fgets(fid);
while ischar(oneline)
    for ii = 1:length(oneline)
        if isletter(oneline(ii))
            output = output + 1;
        end
    end
    oneline = fgets(fid);
end
fclose(fid);
end