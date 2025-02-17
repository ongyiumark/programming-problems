MOD = 1_000_000_007

s = input()

# dp[i][j] is the number of integers in s[:i] that have remainder j when divided by 13 
n = len(s)
dp = [[0 for _ in range(13)] for _ in range(n+1)]
dp[0][0] = 1
for i in range(n):
    for j in range(13):
        if s[i] == "?":
            for num in range(10):
                nj = (j*10+num)%13
                dp[i+1][nj] = (dp[i+1][nj] + dp[i][j])%MOD
        else:
            num = int(s[i])
            nj = (j*10+num)%13
            dp[i+1][nj] = (dp[i+1][nj] + dp[i][j])%MOD

print(dp[n][5])