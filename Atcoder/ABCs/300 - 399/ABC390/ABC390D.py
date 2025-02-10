import sys
sys.setrecursionlimit(10**7)

N = int(input())
A = list(map(int, input().split()))

unique_xors = set()
val = 0
s = [0 for _ in range(N)]

def dfs(idx, sz):
    global val
    for i in range(sz+1):
        val ^= s[i]
        s[i] += A[idx]
        val ^= s[i]

        if idx == N-1: unique_xors.add(val)
        elif i < sz: dfs(idx+1, sz)
        else: dfs(idx+1, sz+1)

        val ^= s[i]
        s[i] -= A[idx]
        val ^= s[i]

dfs(0,0)
print(len(unique_xors))