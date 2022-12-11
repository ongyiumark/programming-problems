#!/bin/bash

for((i = 2; ; ++i)); do
    echo $i;
    ./gen $i > in;
    ./g < in || break;
done