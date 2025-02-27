import math

n = int(input())
points = list()
for _ in range(n):
    points.append(tuple(map(int,input().split())))

points.sort(key=lambda p: math.atan2(p[1], p[0]))

ans = 0
for i in range(n):
    for j in range(n):
        total_x, total_y = 0, 0
        for k in range(i, i+j+1):
            total_x += points[k%n][0]
            total_y += points[k%n][1]
        
        distance = total_x**2 + total_y**2
        ans = max(ans, distance)

print(f"{math.sqrt(ans):.20f}")
