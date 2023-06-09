from functools import lru_cache
import sys
sys.setrecursionlimit(10**5)

q = int(input())

f0 = 'What are you doing at the end of the world? Are you busy? Will you save us?'
fi = 'What are you doing while sending ""? Are you busy? Will you send ""?'

before_recurse_1 = 'What are you doing while sending "'
before_recurse_2 = 'What are you doing while sending ""? Are you busy? Will you send "'

@lru_cache(maxsize=None)
def length(n):
    if n == 0:
        return len(f0)
    return 2*length(n-1)+len(fi)

def solve(n, k):
    if n == 0:
        if k <= len(f0):
            return f0[k-1]
        return '.'
    
    # if its bigger than 60, we don't need to compute the length
    while n > 60 and k > len(before_recurse_1):
        n -= 1
        k -= len(before_recurse_1)
    
    if k <= len(before_recurse_1):
        return before_recurse_1[k-1]

    prev_length = length(n-1)
    if k <= len(before_recurse_1) + prev_length:
        return solve(n-1, k-(len(before_recurse_1)))
    
    if k <= len(before_recurse_2) + prev_length:
        return before_recurse_2[k-1-prev_length]
    
    if k <= len(before_recurse_2) + 2*prev_length:
        return solve(n-1, k-(len(before_recurse_2) + prev_length))

    if k <= length(n):
        return fi[k-1-2*prev_length]

    return '.'

result = []
for _ in range(q):
    n, k = [int(x) for x in input().split()]
    result.append(solve(n, k))

print(''.join(result))