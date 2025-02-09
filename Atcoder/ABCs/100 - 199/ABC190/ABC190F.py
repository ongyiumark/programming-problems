# Solve for number of inversions, then update smartly

n = int(input())
a = [int(x) for x in input().split()]

vals = [0 for i in range(4*n)]

def pull(p):
    vals[p] = vals[p<<1]+vals[p<<1|1]

def update(x, v, p=1, i=0, j=n-1):
    if x <= i and j <= x:
        vals[p] += v
    elif j < x or x < i:
        pass
    else:
        k = (i+j)//2
        update(x, v, p<<1, i, k)
        update(x, v, p<<1|1, k+1, j)
        pull(p)

def query(l, r, p=1, i=0, j=n-1):
    if l <= i and j <= r:
        return vals[p]
    elif j < l or r < i:
        return 0
    else:
        k = (i+j)//2
        return query(l, r, p<<1, i, k) + query(l, r, p<<1|1, k+1, j)

inv = 0
for x in a:
    if x == n:
        continue
    inv += query(x, n-1)
    update(x-1, 1)

print(inv)
for i in range(n-1):
    inv += n-1-2*a[i]
    print(inv)