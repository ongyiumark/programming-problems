from functools import lru_cache

@lru_cache(maxsize=None)
def solve(n):
    if n == 1:
        return ["0", "1"]
    
    nxt = solve(n-1)
    ans = []
    for bit in nxt:
        ans.append("0"+bit)
    for bit in nxt[::-1]:
        ans.append("1"+bit)
    return ans

n = int(input())
for bit in solve(n):
    print(bit)