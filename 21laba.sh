#!/bin/bash

text=$(<~/text/text.txt)

IFS=$1
read -ra newarr <<< "$text"
for val in "${newarr[@]}";
do
 echo "$val"
done