#!/bin/bash
for((i = 1; ; ++i)); do
    echo $i
    ./$1 $i > int
    ./$2 < int||break
done