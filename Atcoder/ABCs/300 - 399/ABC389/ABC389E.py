import sys
input = lambda: sys.stdin.readline().strip()

n, m = list(map(int, input().split()))
P = list(map(int, input().split()))

lo, hi = 0, 10**15
ans_x, ans_cost, ans_units = 0, 0, 0
while lo <= hi:
    mid = hi - (hi-lo)//2
    cost, units = 0, 0
    for p in P:
        k = (mid-1)//p
        if k % 2 == 0:
            k -= 1
        cost += p*((k+1)//2)**2
        if cost > m:
            break
        units += (k+1)//2
    
    if cost <= m:
        ans_x = mid
        ans_cost = cost
        ans_units = units
        lo = mid+1
    else:
        hi = mid-1

for p in P:
    if ans_x % p == 0 and (ans_x//p)%2 == 1 and ans_cost + ans_x <= m:
        ans_units += 1
        ans_cost += ans_x
print(ans_units)
    

        
