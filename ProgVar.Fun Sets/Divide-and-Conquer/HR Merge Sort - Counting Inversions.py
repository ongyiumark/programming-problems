#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'countInversions' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def inversions(X, l, r):
    if r < l:
        return 0, []
    if r == l:
        return 0, [X[l]]

    mid = (l+r)//2
    a, left = inversions(X, l, mid)
    b, right = inversions(X, mid+1, r)

    left_n = len(left)
    right_n = len(right)
    c_left, c_right = 0, 0
    res = []
    total = 0
    while c_left < left_n or c_right < right_n:
        if c_right >= right_n:
            res.append(left[c_left])
            c_left += 1
            continue
        if c_left >= left_n:
            res.append(right[c_right])
            c_right += 1
            total += left_n-c_left
            continue

        if left[c_left] <= right[c_right]:
            res.append(left[c_left])
            c_left += 1
        else:
            res.append(right[c_right])
            c_right += 1 
            total += left_n-c_left

    return total+a+b, res      

def countInversions(arr):
    # Write your code here
    res, sortedX = inversions(arr, 0, len(arr)-1)
    return res

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        arr = list(map(int, input().rstrip().split()))

        result = countInversions(arr)

        fptr.write(str(result) + '\n')

    fptr.close()
