t = int(input())
for _ in range(t):
    n, p = [int(x) for x in input().split()]
    left = 2*n+p
    for i in range(1, n+1):
        for j in range(i+1, n+1):
            if left > 0:
                print(i, j)
                left -= 1
            else:
                break
        if not left:
            break