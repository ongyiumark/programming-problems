import sys
MAXN = 10**5+5
sys.setrecursionlimit(MAXN)

n, m = list(map(int, input().split()))
edges = []
for _ in range(m):
    a, b, y = list(map(int, input().split()))
    a -= 1
    b -= 1
    edges.append((y,a,b))
edges.sort(reverse=True)

queries = []
q = int(input())
for i in range(q):
    v, w = list(map(int, input().split()))
    v -= 1
    queries.append((w,v,i))
queries.sort(reverse=True)

class DSU:
    def __init__(self, n):
        self.n = n
        self.p = [-1 for _ in range(n)]
    
    def find(self, x):
        if self.p[x] < 0:
            return x
        self.p[x] = self.find(self.p[x])
        return self.p[x]
    
    def unite(self, a, b):
        a = self.find(a)
        b = self.find(b)

        if a == b:
            return False

        if self.p[a] > self.p[b]:
            a, b = b, a
        
        self.p[a] += self.p[b]
        self.p[b] = a

        return True

    def size(self, x):
        x = self.find(x)
        return -self.p[x]

dsu = DSU(n)
ans = [None for _ in range(q)]
j = 0

for w, v, i in queries:
    while j < m and edges[j][0] > w:
        y, a, b = edges[j]
        dsu.unite(a, b)
        j += 1
    
    ans[i] = dsu.size(v)

for x in ans:
    print(x)