# Keep track of prefix DP

import sys
input = sys.stdin.readline

h, w = [int(x) for x in input().split()]
grid = ['' for _ in range(h)]
for i in range(h):
    grid[i] = input()

dp = [[0 for j in range(w)] for i in range(h)]
pref_row = [0 for i in range(h)]
pref_col = [0 for j in range(w)]
pref_diag = [0 for d in range(w+h)]
MOD = 10**9+7


for i in range(h):
    for j in range(w):
        if grid[i][j] == '#':
            pref_row[i] = 0
            pref_col[j] = 0
            pref_diag[i-j+w] = 0
            continue

        if i == 0 and j == 0:
            dp[i][j] = 1
        elif i == 0:
            dp[i][j] = pref_row[i]%MOD
        elif j == 0:
            dp[i][j] = pref_col[j]%MOD
        else:
            dp[i][j] = (pref_row[i] + pref_col[j] + pref_diag[i-j+w])%MOD

        pref_row[i] = (pref_row[i] + dp[i][j])%MOD
        pref_col[j] = (pref_col[j] + dp[i][j])%MOD
        pref_diag[i-j+w] = (pref_diag[i-j+w] + dp[i][j])%MOD

print(dp[h-1][w-1])