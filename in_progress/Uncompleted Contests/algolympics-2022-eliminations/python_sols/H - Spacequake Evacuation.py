import sys

input = sys.stdin.readline
def dfs(u, x):
    ans = False
    if u == n-1: return True
    for v in graph[u]:
        if vis[v]: continue
        vis[v] = True
        ans |= dfs(v,x)
        if ans: return ans
    return ans

def valid(x):
    global vis
    vis = [False]*n
    vis[0] = True
    for i in range(n):
        if s[i] < x: vis[i] = True

    if s[0] < x: return False
    if s[n-1] < x: return False
    return dfs(0,x)

def testcase():
    global n, m, s
    n, m = list(map(int,input().split()))
    s = list(map(int,input().split()))

    global graph
    graph = [[] for i in range(n)]
    for i in range(m):
        u, v = list(map(int, input().split()))
        u -= 1
        v -= 1
        graph[u].append(v)
    

    lo = 1
    hi = min(s[0],s[-1])
    ans = 0
    while lo <= hi:
        mid = hi - (hi-lo)//2
        if valid(mid):
            ans = mid
            lo = mid+1
        else:
            hi = mid-1
    print(ans)


T = int(input())

for i in range(T):
    testcase()