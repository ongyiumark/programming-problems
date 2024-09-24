import sys
import math
lines = sys.stdin.readlines()

for line in lines:
    n = int(line)

    s2, s3, s4 = 0, 0, 0
    for i in range(n+1):
        s2 += pow(i, 2)
        s3 += pow(i, 3)
        s4 += pow(i, 4)
    
    r2, r3, r4 = math.comb(n+1, 2), math.comb(n+1, 2), math.comb(n+1, 2)
    r2 = pow(r2, 2)-s2
    r3 = pow(r3, 3)-s3
    r4 = pow(r4, 4)-s4
    print(s2, r2, s3, r3, s4, r4)