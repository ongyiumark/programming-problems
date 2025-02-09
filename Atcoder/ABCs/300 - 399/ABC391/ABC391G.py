MOD = 998_244_353

N, M = list(map(int, input().split()))
S = [ord(i)-ord("a") for i in input()]

dp = dict()
dp[tuple([0]*(N+1))] = 1

for _ in range(M):
    ndp = dict()
    for table, val in dp.items():
        for i in range(26):
            ntable = [0]*(N+1)
            for j in range(1, N+1):
                ntable[j] = max(ntable[j-1], table[j])
                if S[j-1] == i:
                    ntable[j] = max(ntable[j], table[j-1]+1)
            ndp[tuple(ntable)] = (ndp.get(tuple(ntable),0) + val)%MOD
    
    dp = ndp

ans = [0]*(N+1)
for arr, val in dp.items():
    ans[arr[N]] = (ans[arr[N]]+val)%MOD

print(*[i for i in ans])