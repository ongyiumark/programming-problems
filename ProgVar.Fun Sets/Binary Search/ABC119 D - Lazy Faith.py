A, B, Q = [int(x) for x in input().split()]
S = [int(input()) for _ in range(A)]
T = [int(input()) for _ in range(B)]
X = [int(input()) for _ in range(Q)]

def binary_search(V, x):
    lo, hi = 0, len(V)-1
    ans = None
    while lo <= hi:
        mid = hi-(hi-lo)//2
        
        if V[mid] <= x:
            ans = mid
            lo = mid+1
        else:
            hi = mid-1
    
    if ans == None:
        return -float('inf'), V[0]
    elif ans == len(V)-1:
        return V[-1], float('inf')
    else:
        return V[ans], V[ans+1]

from itertools import product
for x in X:
    lr_s = binary_search(S, x)
    lr_t = binary_search(T, x)

    best = float('inf')
    for i, j in product(range(2), repeat=2):
        best = min(best, abs(x-lr_s[i])+abs(lr_s[i]-lr_t[j]))
        best = min(best, abs(x-lr_t[i])+abs(lr_t[i]-lr_s[j]))
    
    print(best)