import sys
input = lambda : sys.stdin.readline().strip()

def mod_pow(b, e, m):
    ans = 1
    while e > 0:
        if e&1: ans = ans*b%m
        b = b*b%m
        e >>= 1
    return ans

p = int(input())
a = list(map(int, input().split()))

MAXN = p
fact = [0]*MAXN
ifact = [0]*MAXN
fact[0] = 1
for i in range(1, MAXN):
    fact[i] = i*fact[i-1]%p
ifact[MAXN-1] = mod_pow(fact[MAXN-1], p-2, p)
for i in range(MAXN-2, -1, -1):
    ifact[i] = (i+1)*ifact[i+1]%p

def comb(n, k):
    return fact[n]*ifact[n-k]%p*ifact[k]%p

poly = [0]*p

count_ones = 0
for i in range(p):
    if a[i] == 0:
        continue
    count_ones += 1

    # (x-i)^(p-1)
    for j in range(p):
        poly[j] += comb(p-1, j)*mod_pow(-i,p-1-j, p)%p
        poly[j] %= p

for i in range(p):
    poly[i] = -poly[i]
    if poly[i] < 0:
        poly[i] += p
poly[0] = (poly[0] + count_ones)%p
print(*poly)