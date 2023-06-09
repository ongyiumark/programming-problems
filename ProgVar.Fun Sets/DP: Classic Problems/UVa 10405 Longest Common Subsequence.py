import sys

def solve(s, t):
    n = len(s)
    m = len(t)

    dp = [[0]*m for _ in range(n)]

    for i in range(n):
        for j in range(m):
            if i == 0 and j == 0: dp[i][j] = int(s[i] == t[j])
            elif i == 0: dp[i][j] = max([dp[i][j], dp[i][j-1], int(s[i]==t[j])])
            elif j == 0: dp[i][j] = max([dp[i][j], dp[i-1][j], int(s[i]==t[j])])
            else: dp[i][j] = max([dp[i][j], dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+(s[i]==t[j])])
    
    return dp[n-1][m-1]

lines = sys.stdin.readlines()
sz = len(lines)
idx = 0

while idx < sz:
    s = lines[idx].strip()
    t = lines[idx+1].strip()

    print(solve(s, t))
    idx += 2