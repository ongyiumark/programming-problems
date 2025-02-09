n, m = [int(x) for x in input().split()]
h = [int(x) for x in input().split()]

ar = [True]*n
for _ in range(m):
    a, b = [int(x)-1 for x in input().split()]
    if h[a] == h[b]:
        ar[a] = False
        ar[b] = False
    elif h[a] > h[b]:
        ar[b] = False
    else:
        ar[a] = False

print(sum(ar))