#!/bin/bash
for((i = 1; ; ++i)); do
    echo $i
    python3 gen.py $i > 1.in
    python3 testing_tool.py -f 1.in ./j
    
    ex=$?
    [[ $ex -ne 0 ]]&& break
done