n, x = [int(x) for x in input().split()]
coins = [int(x) for x in input().split()]
dp = [0]*(x+1)
dp[0] = 1

mod = 10**9+7
for i in range(x+1):
    for c in coins:
        if i-c < 0:
            continue
        dp[i] += dp[i-c]
    dp[i] %= mod
    
print(dp[x])
