from collections import deque

n, k = [int(x) for x in input().split()]
arr = list(range(n))

def count(l, r):
    if r-l == 1:
        return 0
    
    mid = (l+r)>>1
    return 2+count(l,mid)+count(mid, r)

if k%2 == 0 or k > 1+count(0, n):
    print(-1)
    exit(0)

intervals = deque([(0, n)])
while k > 1:
    l, r = intervals.popleft()
    if r-l == 1:
        intervals.append((l,r))
        continue
    
    mid = (l+r)>>1
    intervals.append((l, mid))
    intervals.append((mid, r))
    k -= 2

res = sorted(list(intervals))[::-1]
curr = 1
for l, r in res:
    for i in range(l, r):
        arr[i] = curr
        curr += 1

print(*arr)


