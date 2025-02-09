# Try all 2^k possible combinations

n, m = [int(x) for x in input().split()]

A = [0 for i in range(m)]
B = [0 for i in range(m)]

for i in range(m):
    A[i], B[i] = [int(x) for x in input().split()]

k = int(input())

C = [0 for i in range(k)]
D = [0 for i in range(k)]

for i in range(k):
    C[i], D[i] = [int(x) for x in input().split()]

ans = 0
for mask in range((1<<k)):
    dishes = [0 for x in range(n+1)]
    for i in range(k):
        if (1<<i)&mask:
            dishes[C[i]] += 1
        else:
            dishes[D[i]] += 1

    cnt = 0
    for i in range(m):
        cnt += (dishes[A[i]] >= 1 and dishes[B[i]] >= 1)
    ans = max(cnt, ans)

print(ans)