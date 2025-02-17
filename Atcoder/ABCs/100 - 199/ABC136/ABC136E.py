n, k = list(map(int, input().split()))
a = list(map(int, input().split()))
s = sum(a)

def solve(d):
    """Counts the least number of operations required to make the whole list divisible by d"""
    rems = [None]*n
    for i in range(n):
        rems[i] = a[i]%d
    
    rems.sort()
    pref = [0]*n
    pref[0] = rems[0]
    for i in range(1, n):
        pref[i] = pref[i-1]+rems[i]

    total = float("inf")
    for i in range(n):
        if pref[i] == d*(n-i-1)-(pref[n-1]-pref[i]):
            total = min(total, pref[i])

    return total

ans = 1
i = 1
while i*i <= s:
    if s%i != 0:
        i += 1
        continue
    
    if solve(i) <= k:
        ans = max(ans, i)
    if solve(s//i) <= k:
        ans = max(ans, s//i)

    i += 1
print(ans)