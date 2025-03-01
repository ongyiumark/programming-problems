n = int(input())
a = list(map(int, input().split()))

costs = [None for _ in range(n)]
costs[0] = 0

for i in range(1, n):
    costs[i] = costs[i-1] + abs(a[i]-a[i-1])
    if i >= 2:
        costs[i] = min(costs[i], costs[i-2]+abs(a[i]-a[i-2]))

print(costs[n-1])