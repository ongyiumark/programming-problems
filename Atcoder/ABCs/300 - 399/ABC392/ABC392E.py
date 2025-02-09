n, m = list(map(int, input().split()))
edges = list()
for _ in range(m):
    a, b = list(map(int, input().split()))
    a -= 1
    b -= 1
    edges.append((a,b))


class UnionFind:
    def __init__(self, n):
        self.n = n
        self.p = [-1]*n
    
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

uf = UnionFind(n)
double_edges = list()
for i, (a, b) in enumerate(edges):
    res = uf.unite(a, b)
    if not res:
        double_edges.append((i,a,b))

disjoint_sets = set()
for i in range(n):
    disjoint_sets.add(uf.find(i))


ans = list()
for i, a, b in double_edges:
    p = uf.find(a)
    disjoint_sets.remove(p)

    if len(disjoint_sets) == 0:
        break
    na = next(iter(disjoint_sets))
    disjoint_sets.remove(na)

    ans.append((i, a, na))

    uf.unite(a, na)
    np = uf.find(a)
    disjoint_sets.add(np)


print(len(ans))
for i, a, na in ans:
    print(i+1, a+1, na+1)