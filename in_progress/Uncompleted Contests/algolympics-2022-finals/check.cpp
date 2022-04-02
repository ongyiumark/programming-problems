#!/bin/bash

for ((i = 1; ; ++i)); do
    echo $1
    ./$1 $i > int
    diff -w <(./$2 < int) <(./$3 < int) || break
done