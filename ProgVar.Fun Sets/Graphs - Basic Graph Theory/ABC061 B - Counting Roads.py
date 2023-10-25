n, m = [int(x) for x in input().split()]
ans = [0]*n

for i in range(m):
    a, b = [int(x) for x in input().split()]
    ans[a-1] += 1
    ans[b-1] += 1

print(*ans, sep='\n')