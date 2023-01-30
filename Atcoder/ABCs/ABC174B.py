n, d = [int(x) for x in input().split()]
cnt = 0
for _ in range(n):
    x, y = [int(x) for x in input().split()]
    cnt += (x*x + y*y <= d*d)
print(cnt)