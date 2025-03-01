n = int(input())
sq = 1
while (sq+1)*(sq+1) <= n:
    sq += 1
sq2 = sq*sq

memo = [None for _ in range(n-sq2+1)]
memo[0] = 0
def solve(m):
    if memo[m-sq2] is not None:
        return memo[m-sq2]
    
    ans = float("inf")
    d = 1
    while d*d <= m:
        if m % d == 0:
            ans = min(ans, abs(d-m//d))
        d += 1
    
    for i in range(1, m-sq2+1):
        ans = min(ans, solve(m-i)+i)
    memo[m-sq2] = ans
    return ans

print(solve(n))