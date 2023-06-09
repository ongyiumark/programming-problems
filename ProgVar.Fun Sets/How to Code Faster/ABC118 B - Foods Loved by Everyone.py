n, m = [int(x) for x in input().split()]
foods = [[False]*n for i in range(m)]

for i in range(n):
    liked = [int(x)-1 for x in input().split()][1:]
    for x in liked:
        foods[x][i] = True

count = 0
for lst in foods:
    count += all(lst)

print(count)