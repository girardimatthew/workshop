echo "The # here does not begin a comment."
echo 'The # here does not begin a comment.'
echo The \# here does not begin a comment.
echo The # here begins a comment.
echo ${PATH#*:}       # Parameter substitution, not a commen
echo $(( 2#101011 ))  # Base conversion, not a comment.
# Thanks, S.C.
