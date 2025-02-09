# Union-Find but also keep a dictionary of colors

class union_find():
    def __init__(self, n, color):
        self.p = [-1 for i in range(n)]
        self.c = [dict() for i in range(n)]

        for i in range(n):
            self.c[i][color[i]] = 1
    
    def find(self, x):
        if self.p[x] < 0:
            return x
        else:
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
        for key, val in self.c[b].items():
            self.c[a][key] = self.c[a].get(key, 0) + val
        self.p[b] = a 

        return True

n, q = [int(x) for x in input().split()]
c = [int(x) for x in input().split()]


uf = union_find(n, c)
for _ in range(q):
    t, a, b = [int(x) for x in input().split()]
    if t == 1:
        uf.unite(a-1, b-1)
    else:
        x = uf.find(a-1)
        print(uf.c[x].get(b, 0))