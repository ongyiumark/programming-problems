n, m = list(map(int, input().split()))
jobs = [None]*n
for i in range(n):
    jobs[i] = list(map(int, input().split()))

levels = [list() for _ in range(m+1)]
for i in range(n):
    a, b = jobs[i]
    if a > m:
        continue
    levels[a].append(b)

from heapq import heappush, heappop
pq = []

total = 0
for i in range(1, m+1):
    for reward in levels[i]:
        heappush(pq, -reward)
    
    if len(pq) > 0:
        total += -heappop(pq)
print(total)