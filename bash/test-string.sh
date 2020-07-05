#!/bin/bash

str1=""
str2="Sad"
str3="Happy"

if [ "$str1" ]; then
  echo "$str1 is not null"
fi

# if str has a value or not
if [ -z "$str1" ]; then
  echo "str1 has no value"
fi

# check equality 
if [ "$str2" == "$str3" ]; then
  echo "$str2 equals $str3"
elif [ "$str2" != "$str3" ]; then
  echo "str2 is not equal to $str3"
fi
