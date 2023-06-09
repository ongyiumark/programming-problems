import sys
input = sys.stdin.readline

n = int(input())
L = sorted([int(x) for x in input().split()])

# a < b + c ---> a-b < c
# b < a + c ---> b-a < c
# c < a + b ---> c < a+b
# ==> abs(a-b) < c < a+b

total = 0

from itertools import product
for a, b in product(range(n), repeat=2):
    if a == b:
        continue
    
    lo, hi = 0, n-1
    l_ans, r_ans = n, -1
    while lo <= hi:
        mid = hi - (hi-lo)//2

        if abs(L[a]-L[b]) < L[mid]:
            l_ans = mid
            hi = mid-1
        else:
            lo = mid+1

    lo, hi = 0, n-1
    while lo <= hi:
        mid = hi - (hi-lo)//2

        if L[mid] < L[a]+L[b]:
            r_ans = mid
            lo = mid+1
        else:
            hi = mid-1
    

    if r_ans < l_ans:
        continue
    
    res = r_ans-l_ans+1
    if l_ans <= a <= r_ans:
        res -= 1
    if l_ans <= b <= r_ans:
        res -= 1

    total += max(res, 0)

print(total//6)