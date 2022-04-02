from functools import lru_cache
import sys
sys.setrecursionlimit(500*500)

n = int(input())
A = input()
B = input()

M = 10**9+7
N = 501

def gcd(a, b):
    if b == 0: return a
    return gcd(b, a%b)

def lcm(a,b):
    return a//gcd(a,b)*b

def modpow(b, e):
    ans = 1
    while e > 0:
        if e%2 == 1: ans = ans*b%M
        b = b*b%M
        e //= 2
    return ans

def modinv(x):
    return modpow(x, M-2)

pow2 = [1]*N
for i in range(1,N):
    pow2[i] = pow2[i-1]*2%M

fact = [1]*N
for i in range(1,N):
    fact[i] = fact[i-1]*i%M

def perm(n ,k):
    return fact[n]*modinv(fact[n-k])%M

def comb(n, k):
    return perm(n,k)*modinv(fact[k])%M

def reduce(a):
    g = gcd(a[0], a[1])
    ans = (a[0]//g, a[1]//g)
    return (ans[0]%M, ans[1]%M)

def addfrac(a, b):
    L = lcm(a[1],b[1])
    num = L//a[1]*a[0] + L//b[1]*b[0]
    den = L
    return reduce((num,den))

@lru_cache
def solve(a, b):
    if a == 0 or b == 0: return (0,1)
    t = a+b
    num = (pow2[t],1)
    for i in range(1,a):
        tmp = solve(a-i,b)
        num = addfrac(num, (comb(a,i)*tmp[0],tmp[1]))
        num = reduce(num)
    for i in range(1,b):
        tmp = solve(a, b-i)
        num = addfrac(num, (comb(b,i)*tmp[0],tmp[1]))
        num = reduce(num)
    
    print(a, b, num[0], '/', num)
    den = pow2[a]+pow2[b]-3

    ans = (num[0],num[1]*den)
    return reduce(ans)

acnt = 0
bcnt = 0

for i in range(n):
    if A[i] == 'B' and B[i] == 'G': acnt += 1
    if A[i] == 'G' and B[i] == 'B': bcnt += 1

ans = solve(acnt, bcnt)


ans = (ans[0]%M, ans[1]%M)
print(ans[0]*modinv(ans[1])%M)