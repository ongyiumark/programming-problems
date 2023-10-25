m, n = [int(x) for x in input().split()]
t = [[0]*n for _ in range(m)]
for i in range(m):
    t[i] = [int(x) for x in input().split()]

dp = [[0]*n for _ in range(m)]

for i in range(m):
    for j in range(n):
        if i > 0:
            dp[i][j] = max(dp[i-1][j],dp[i][j])
        if j > 0:
            dp[i][j] = max(dp[i][j-1],dp[i][j])
    
        dp[i][j] += t[i][j]

res = []
for i in range(m):
    res.append(dp[i][n-1])
print(*res)