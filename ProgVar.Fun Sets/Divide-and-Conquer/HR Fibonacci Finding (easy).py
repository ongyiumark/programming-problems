#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'solve' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER a
#  2. INTEGER b
#  3. INTEGER n
#

def solve(a, b, n):
    MOD = 10**9+7
    def matmult(A, B):
        C = [[0]*2 for _ in range(2)]
        n = len(A)
        p = len(B)
        m = len(B[0])

        for k in range(p):
            for i in range(n):
                for j in range(m):
                    C[i][j] += A[i][k]*B[k][j]
                    C[i][j] %= MOD
        return C

    def matpow(A, n):
        ans = [[1, 0], [0, 1]]
        A = list(A)
        while n > 0:
            if n&1:
                ans = matmult(ans, A)
            A = matmult(A, A)
            n >>= 1
        return ans

    A, B, N =  a, b, n
    pre_mult = [[0, 1], [1, 1]]
    start = [[A], [B]]

    res = matmult(matpow(pre_mult, N), start)
    return res[0][0]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        first_multiple_input = input().rstrip().split()

        a = int(first_multiple_input[0])

        b = int(first_multiple_input[1])

        n = int(first_multiple_input[2])

        result = solve(a, b, n)

        fptr.write(str(result) + '\n')

    fptr.close()