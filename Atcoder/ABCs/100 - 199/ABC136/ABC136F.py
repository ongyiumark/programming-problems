MOD = 998_244_353
n = int(input())
p = [None]*n

x_coords = [None]*n
y_coords = [None]*n
for i in range(n):
    p[i] = tuple(map(int,input().split()))
    x_coords[i] = p[i][0]
    y_coords[i] = p[i][1]

p.sort()

# coordinate compression
x_coords.sort()
y_coords.sort()

x_compress = dict()
y_compress = dict()
for i in range(n):
    x_compress[x_coords[i]] = i+1   # 1-indexed for fenwick tree
    y_compress[y_coords[i]] = i+1


class FenwickTree:
    def __init__(self, n):
        self.p = [0]*(n+1)

    def update(self, i, v):
        while i < len(self.p):
            self.p[i] += v
            i += (i&-i)

    def query(self, i):
        total = 0
        while i > 0:
            total += self.p[i]
            i -= (i&-i)
        return total

top_left = [None]*n
bottom_left = [None]*n
top_right = [None]*n
bottom_right = [None]*n

ft = FenwickTree(n)
for i in range(n):
    x, y = p[i]
    ft.update(y_compress[y], 1)

    bottom_left[i] = ft.query(y_compress[y]-1)
    top_left[i] = ft.query(n)-ft.query(y_compress[y])

ft = FenwickTree(n)
for i in range(n-1, -1, -1):
    x, y = p[i]
    ft.update(y_compress[y], 1)

    bottom_right[i] = ft.query(y_compress[y]-1)
    top_right[i] = ft.query(n)-ft.query(y_compress[y])


def mod_pow(b, e):
    ans = 1
    while e > 0:
        if e&1: ans = ans*b%MOD
        b = b*b %MOD
        e >>= 1

    return ans

contribution = [None]*n
for i in range(n):
    contribution[i] = mod_pow(2, n)-1
    
    contribution[i] -= mod_pow(2, top_left[i]+bottom_left[i])
    contribution[i] %= MOD

    contribution[i] -= mod_pow(2, top_left[i]+top_right[i])
    contribution[i] %= MOD

    contribution[i] -= mod_pow(2, top_right[i]+bottom_right[i])
    contribution[i] %= MOD

    contribution[i] -= mod_pow(2, bottom_left[i]+bottom_right[i])
    contribution[i] %= MOD

    contribution[i] += mod_pow(2, top_left[i])
    contribution[i] %= MOD

    contribution[i] += mod_pow(2, bottom_left[i])
    contribution[i] %= MOD

    contribution[i] += mod_pow(2, top_right[i])
    contribution[i] %= MOD

    contribution[i] += mod_pow(2, bottom_right[i])
    contribution[i] %= MOD

    if contribution[i] < 0:
        contribution[i] += MOD

total = 0
for i in range(n):
    total = (total + contribution[i])%MOD

print(total)