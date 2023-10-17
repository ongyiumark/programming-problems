#!/bin/bash
for ((i = 1; ; i++)); do
  echo $i
  ./$1 $i > int
  diff <(./$2 < int) <(./$3 < int) || break
done