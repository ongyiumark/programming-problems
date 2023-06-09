n, m, q = [int(x) for x in input().split()]
quad = []
for _ in range(q):
    a, b, c, d = [int(x) for x in input().split()]
    quad.append((a,b,c,d))

def compute(A):
    total = 0
    for i in range(q):
        a, b, c, d = quad[i]
        if A[b-1]-A[a-1] == c:
            total += d
    return total

best = 0
def backtrack(i, A):
    global best
    if i == n:
        tmp = compute(A)
        best = max(best, tmp)
        return
    
    for j in range(1, m+1):
        A.append(j)
        backtrack(i+1, A)
        A.pop()

A = []
backtrack(0, A)
print(best)