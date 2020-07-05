
function A = sparse_array_in( filename )
fid = fopen( filename,'r' );
if fid < 0
    A = [];
    return; %// Change
end

% Read size of array and number of non-zero elements
rows = fread( fid,1,'uint32'); %// Change
cols = fread( fid,1,'uint32'); %// Change
dims = [ rows,cols ];
non_zero = fread( fid,1,'uint32' ); %// Change
% Create array of zeros
A = zeros( dims );   
% Fill array A with the values from the file
for i = 1:non_zero
    r = fread( fid,1,'uint32' ); %// Change
    c = fread( fid,1,'uint32' ); %// Change
    v = fread( fid,1,'double' ); %// Change
    A(r,c) = v;
end
%// Change - remove reshape
fclose( fid );
end
