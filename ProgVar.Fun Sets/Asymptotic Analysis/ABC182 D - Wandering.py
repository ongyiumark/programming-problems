n = int(input())
A = [int(x) for x in input().split()]

pref = [0]*n
pref[0] = A[0]
for i in range(1, n):
    pref[i] = pref[i-1]+A[i]

pref_max = [-float('inf')]*n
pref_max[0] = pref[0]
for i in range(1, n):
    pref_max[i] = max(pref_max[i-1], pref[i])

total = 0
ans = 0
for i in range(n):
    ans = max(total+pref_max[i], ans)
    total += pref[i]

print(ans)