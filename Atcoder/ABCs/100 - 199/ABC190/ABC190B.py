n, s, d = [int(x) for x in input().split()]
cnt = 0
for _ in range(n):
    x, y = [int(x) for x in input().split()]
    cnt += ((x < s) and (y > d))
print("Yes") if cnt > 0 else print("No")