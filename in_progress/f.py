# fast io
import sys
input = sys.stdin.readline
print = lambda x: sys.stdout.write(str(x) + "\n")
sys.setrecursionlimit(10**9)

# read colors
n, q = [int(x) for x in input().split()]
c = [int(x)-1 for x in input().split()]

# read queries
queries = [(0,0,0) for _ in range(q)]
for i in range(q):
    l, r = [int(x)-1 for x in input().split()]
    queries[i] = (l, r, i)

# sort queries by r
compare = lambda x,y: x[1]-y[1]
from functools import cmp_to_key
queries.sort(key=cmp_to_key(compare))

# store last appearance of color i
last = [-1 for _ in range(n)]

# segment tree
class SegmentTree:
    def __init__(self, l, r):
        self.l = l
        self.r = r

        if l == r:
            self.value = 0
        else:
            k = (l+r)>>1
            self.left = SegmentTree(l, k)
            self.right = SegmentTree(k+1, r)
            self.value = self.right.value + self.left.value
    
    def update(self, x, v):
        if x <= self.l and self.r <= x:
            self.value += v
        elif self.r < x or x < self.l:
            pass
        else:
            self.right.update(x,v)
            self.left.update(x,v)
            self.value = self.right.value + self.left.value
    
    def query(self, l, r):
        if l <= self.l and self.r <= r:
            return self.value
        elif self.r < l or r < self.l:
            return 0
        else:
            return self.right.query(l,r)+self.left.query(l,r)

st = SegmentTree(0, n-1)

# answer queries 
j = -1
ans = [0 for _ in range(q)]
for k in range(q):
    l, r, i = queries[k]
    while j < r:
        j += 1
        if last[c[j]] != -1:
            st.update(last[c[j]], -1)
        st.update(j, 1)
        last[c[j]] = j

    ans[i] = st.query(l, r)

# print answer
for i in range(q):
    print(ans[i])
