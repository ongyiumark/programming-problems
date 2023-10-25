n, m = [int(x) for x in input().split()]
deg = [0]*n
for _ in range(m):
    a, b = [int(x) for x in input().split()]
    deg[a-1] += 1
    deg[b-1] += 1

count_ones = 0
count_twos = 0
for i in range(n):
    count_ones += (deg[i] == 1)
    count_twos += (deg[i] == 2)

if count_ones == 0 and count_twos == n:
    print("ring topology")
elif count_ones == 2 and count_twos == n-2:
    print("bus topology")
elif count_ones == n-1:
    print("star topology")
else:
    print("unknown topology")
