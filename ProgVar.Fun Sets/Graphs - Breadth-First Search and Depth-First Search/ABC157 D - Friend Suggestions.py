import sys
input = sys.stdin.readline

n, m, k = [int(x) for x in input().split()]
adj_list = [[] for _ in range(n)]
block_list = [[] for _ in range(n)]

for _ in range(m):
    a, b = [int(x)-1 for x in input().split()]
    adj_list[a].append(b)
    adj_list[b].append(a)

for _ in range(k):
    a, b = [int(x)-1 for x in input().split()]
    block_list[a].append(b)
    block_list[b].append(a)


class DSU():
    def __init__(self, n):
        self.p = [-1]*n
    
    def find(self, x):
        if self.p[x] < 0:
            return x
        
        self.p[x] = self.find(self.p[x])
        return self.p[x]
    
    def union(self, a, b):
        a = self.find(a)
        b = self.find(b)

        if a == b: return False

        if self.p[a] > self.p[b]:
            a, b = b, a

        self.p[a] += self.p[b]
        self.p[b] = a
        return True
    
    def compare(self, a, b):
        a = self.find(a)
        b = self.find(b)

        return a == b
    
    def size(self, x):
        x = self.find(x)
        return -self.p[x]

uf = DSU(n)

for u in range(n):
    for v in adj_list[u]:
        uf.union(u,v)

ans = [0]*n
for u in range(n):
    count = 0
    for v in block_list[u]:
        count += uf.compare(u, v)
    
    ans[u] = uf.size(u) - 1 - count - len(adj_list[u])

print(*ans)