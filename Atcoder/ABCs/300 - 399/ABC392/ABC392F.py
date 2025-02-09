N = int(input())
P = list(map(int, input().split()))

A = [1 for i in range(N)]

class FenwickTree:
    def __init__(self, ar):
        self.ar = ar
        self.n = len(self.ar)
        self.tree = [0 for _ in range(self.n+1)]

        for i in range(1, self.n+1):
            self.tree[i] += ar[i-1]
            if i+(i&-i) <= self.n:
                self.tree[i+(i&-i)] += self.tree[i]

    def update(self, i, delta):
        while i < self.n:
            self.tree[i] += delta
            i += i&(-i)

    def query(self, i):
        res = 0
        while i > 0:
            res += self.tree[i]
            i -= i&(-i)
        return res

ft = FenwickTree(A)

indices = list()
for i, p in enumerate(P[::-1]):
    lo, hi = 1, N
    idx = -1
    while lo <= hi:
        mid = hi - (hi-lo)//2
        if ft.query(mid) >= p:
            hi = mid-1
            idx = mid
        else:
            lo = mid+1
    indices.append(idx)
    ft.update(idx, -1)

ans = [0 for _ in range(N)]
for i, idx in enumerate(indices[::-1]):
    ans[idx-1] = i+1
print(*ans)