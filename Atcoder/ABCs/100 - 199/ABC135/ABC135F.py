import sys
sys.setrecursionlimit(2_000_000)

s = input()
t = input()

n = len(t)
m = len(s)

# calculate prefix table of t
LPS = [0]*n
i, j = 1, 0
while i < n:
    if t[i] == t[j]:
        j += 1
        LPS[i] = j
        i += 1
    else:
        if j != 0:
            j = LPS[j-1]
        else:
            LPS[i] = 0
            i += 1

# KMP algorithm
match_table = [False]*m
i, j = 0, 0
while i < m+n-1:
    if s[i%m] != t[j]:
        if j != 0:
            j = LPS[j-1]
        else:
            i += 1
    else:
        i += 1
        j += 1
    
    if j == n:
        match_table[(i-j)%m] = True
        j = LPS[j-1]

vis = [0]*m
ans = [0]*m
def dfs(u):
    if match_table[u]:
        v = (u+n)%m
        if vis[v] == 1:
            ans[u] = float("inf")
            return ans[u]
        if vis[v] == 2:
            ans[u] = 1+ans[v]
            return ans[u]

        vis[v] = 1
        ans[u] = 1+dfs(v)
        vis[v] = 2

        return ans[u]
    else:
        return 0

for u in range(m):
    if match_table[u]:
        if vis[u] == 2:
            continue
        vis[u] = 1
        ans[u] = dfs(u)
        vis[u] = 2
    else:
        ans[u] = 0

result = max(ans)

print(-1 if result == float("inf") else result) 