#!/bin/bash

folders=$(ls -d ./*/)

OLD_IFS=IFS
IFS=$'\n'
for folder in $folders ; do
  file="$folder""a.out"
  echo "$file"
  rm -f "$file"
done
IFS=$OLD_IFS
