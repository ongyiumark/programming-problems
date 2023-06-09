def solve(A, B):
    for a in range(h):
        for b in range(w):
            val = True
            for i in range(h):
                for j in range(w):
                    if A[i][j] != B[(a+i)%h][(b+j)%w]:
                        val = False
                        break
                if not val:
                    break
            if val:
                return True
    return False

h, w = [int(x) for x in input().split()]
A = [input() for _ in range(h)]
B = [input() for _ in range(h)]

if solve(A, B):
    print("Yes")
else:
    print("No")