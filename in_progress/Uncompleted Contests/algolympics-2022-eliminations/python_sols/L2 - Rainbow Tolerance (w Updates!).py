import sys
input = sys.stdin.readline

M = 10**9 + 6969
n = int(input())
u = [int(x) for x in input().split()]

fact = [0 for i in range(n+1)]
revfact = [0 for i in range(n+1)]

fact[0] = 1
for i in range(1,n+1):
    fact[i] = fact[i-1]*i%M

revfact[n] = n
for i in range(n-1, 0, -1):
    revfact[i] = i*revfact[i+1]%M

cnt = [0 for i in range(n)]
cnt[n-1] = fact[n-1]
for i in range(n-2, -1, -1):
    cnt[i] = (cnt[i+1] + fact[i]*revfact[i+2])%M

ans = sum([a*b for a,b in zip(cnt,u)])%M

print(ans)
Q = int(input())
for qq in range(Q):
    i, x = [int(s) for s in input().split()]
    ans = ans - cnt[i]*u[i] + cnt[i]*x
    u[i] = x
    ans %= M
    if ans < 0: ans += M
    print(ans)