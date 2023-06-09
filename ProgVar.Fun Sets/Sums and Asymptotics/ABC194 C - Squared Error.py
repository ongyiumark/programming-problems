n = int(input())
A = [int(x) for x in input().split()]

total = 0
for i in range(1, n):
    total += A[i]*A[i]*i

pref = [0]*n
pref[0] = A[0]
for i in range(1, n):
    pref[i] += pref[i-1]+A[i]
for i in range(1, n):
    total += -2*A[i]*pref[i-1]

pref2 = [0]*n
pref2[0] = A[0]*A[0]
for i in range(1, n):
    pref2[i] += pref2[i-1]+A[i]*A[i]
for i in range(1, n):
    total += pref2[i-1]

print(total)
