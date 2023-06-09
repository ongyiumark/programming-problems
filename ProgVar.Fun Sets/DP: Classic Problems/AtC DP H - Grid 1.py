h, w = [int(x) for x in input().split()]
grid = [input() for _ in range(h)]
dp = [[0]*w for _ in range(h)]

MOD = 10**9+7
dp[0][0] = 1
for i in range(h):
    for j in range(w):
        if grid[i][j] == '#':
            dp[i][j] = 0
            continue
        if i-1 >= 0:
            dp[i][j] += dp[i-1][j]
        if j-1 >= 0:
            dp[i][j] += dp[i][j-1]

        dp[i][j] %= MOD
print(dp[h-1][w-1])
        