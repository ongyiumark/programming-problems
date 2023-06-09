n = int(input())
A = [int(x) for x in input().split()]

suffix = [0]*n
suffix[n-1] = A[n-1]
for i in range(n-2, -1, -1):
    suffix[i] += suffix[i+1]+A[i]

MOD = 10**9+7
total = 0
for i in range(n-1):
    total += A[i]*suffix[i+1]
    total %= MOD

print(total)
