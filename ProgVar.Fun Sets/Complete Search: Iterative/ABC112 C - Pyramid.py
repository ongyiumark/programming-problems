from itertools import product

n = int(input())
coords = []

minh = 0
for _ in range(n):
    x, y, h = [int(x) for x in input().split()]
    coords.append((x,y,h))
    minh = max(minh, h)

for cx, cy in product(range(101), repeat=2):
    for H in range(201):
        val = True
        for x, y, h in coords:
            val &= max(H+minh-abs(x-cx)-abs(y-cy), 0) == h
            if not val:
                break
        
        if val:
            print(cx, cy, H+minh)
            exit(0)