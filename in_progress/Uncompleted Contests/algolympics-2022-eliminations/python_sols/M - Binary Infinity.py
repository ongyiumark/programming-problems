from functools import lru_cache
import sys
input = sys.stdin.readline

M = 10**9 + 7
N = 505

n = int(input())
A = input()
B = input()

acnt, bcnt = 0, 0
for i in range(n):
    if A[i] != B[i]:
        if A[i] == 'B': acnt += 1
        else: bcnt += 1

comb = [[0 for j in range(N)] for i in range(N)]
for i in range(N):
    for j in range(i+1):
        if j == 0: comb[i][j] = 1
        else: comb[i][j] = (comb[i-1][j-1] + comb[i-1][j])%M

pow2 = [0 for i in range(N)]
pow2[0] = 1
for i in range(1,N):
    pow2[i] = pow2[i-1]*2%M

def gcd(a, b):
    if b == 0: return a
    return gcd(b, a%b)

def modpow(b, e):
    ans = 1
    while e > 0:
        if e&1: ans = ans*b%M
        b = b*b%M
        e >>= 1
    return ans

def modinv(x):
    return modpow(x, M-2)

dp = [[-1 for j in range(N)] for i in range(N)]
def solve(a, b):
    if a == 0 or b == 0: return 0
    if a > b: a, b = b, a
    if dp[a][b] != -1: return dp[a][b]
    num = pow2[a+b]
    for i in range(1, a):
        num = num + comb[a][i]*solve(a-i,b)%M
    for i in range(1, b):
        num = num + comb[b][i]*solve(a,b-i)%M
    num %= M
    den = (pow2[a]+pow2[b]-3)%M
    if den < 0: den += M
    g = gcd(num, den)
    num //= g
    den //= g
    dp[a][b] = num*modinv(den)%M
    return dp[a][b]

print(solve(acnt, bcnt))