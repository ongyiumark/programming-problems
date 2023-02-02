# Difference array. Range update, point query.

n, w = [int(x) for x in input().split()]

N = 2*10**5
diff = [0 for _ in range(N+5)]


for i in range(n):
    s, t, p = [int(x) for x in input().split()]
    diff[s] += p
    diff[t] -= p

for i in range(1,N+1):
    diff[i] += diff[i-1]

if all([x <= w for x in diff]):
    print("Yes")
else:
    print("No")