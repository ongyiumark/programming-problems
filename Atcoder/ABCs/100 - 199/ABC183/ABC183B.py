# Math on similar triangles

sx, sy, gx, gy = [int(x) for x in input().split()]
gy = -gy

if sx < gx:
    print(sx + sy*(abs(gx-sx)/abs(gy-sy)))
else:
    print(gx + -gy*(abs(gx-sx)/abs(gy-sy)))