N = 1000+5
A = ''
B = ''
 
dp = [[-1]*N for i in range(N)]
pref = [0]*N
suff = [0]*N
 
def solve(l, r):
    if dp[l][r] != -1: return dp[l][r]
    ans = 0
    if l == r: ans = int(A[l]==B[l])
    elif l > r: ans = 0
    else: ans = int(A[l]==B[r]) + int(A[r]==B[l]) + solve(l+1,r-1)
    dp[l][r] = ans
    return ans
 
def get_pref(a):
    if a < 0: return 0
    return pref[a]
 
def get_suff(b):
    if b >= len(A): return 0
    return suff[b]
 
def testcase():
    global A,B
    A = input()
    B = input()
    n = len(A)
 
    for i in range(n):
        for j in range(n):
            dp[i][j] = -1
 
    for i in range(n):
        pref[i] = 0
        if A[i] == B[i]:
            pref[i] += 1
        if i > 0:
            pref[i] += pref[i-1]

    for i in range(n-1,-1,-1):
        suff[i] = 0
        if A[i] == B[i]:
            suff[i] += 1
        if i < n-1:
            suff[i] += suff[i+1]
    
    ans = 0
    for i in range(n):
        for j in range(i,n):
            ans = max(ans, get_pref(i-1)+solve(i,j)+get_suff(j+1))
    print(ans)
 
T = int(input())
 
for i in range(T):
    testcase()