#!/bin/bash

echo hello
echo $?			# Exit status 0 returned because command successful

lskdf			# Unrecognized commnad. 
echo $?			# Non-zero exit status returned.

echo

exit 113		# will return 113 to shell

# To verify this, type "echo $?" after script terminates.
# By convention, an 'exit 0' indicates success,
# while a non−zero exit value means an error or anomalous condition.
