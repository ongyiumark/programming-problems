from itertools import product

n = int(input())
a = [int(x) for x in input().split()]

ans = 0
for i, j in product(range(n), repeat=2):
    if i > j:
        continue

    for k in range(i, j+1):
        a[k] = 1-a[k]

    ans = max(ans, sum(a))

    for k in range(i, j+1):
        a[k] = 1-a[k]

print(ans)