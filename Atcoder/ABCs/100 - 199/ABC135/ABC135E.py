k = int(input())
x, y = list(map(int,input().split()))

# assume 1st quadrant
x_flip = -1 if (x < 0) else 1
y_flip = -1 if (y < 0) else 1
x, y = abs(x), abs(y)

# assume x > y
swap_flag = (x < y)
if swap_flag:
    x, y = y, x

def solve():
    if k%2 == 0 and (x+y)%2==1:
        return None
    
    if x+y == k:
        return [(x, y)] 

    if x+y < k:
        if (x+y)%2 == 0:
            return [((x+y)//2, -(2*k-x-y)//2), (x, y)]

        return [(x, -(k-x)), (x+(k+x-y)//2, (-k+x+y)//2),(x,y)]

    n = (x+y + k-1)//k # ceil((x+y)/k)
    if (k*n-x-y)%2 == 1:
        n += 1
    assert (k*n-x-y)%2 == 0 and (k*n-x+y)%2 == 0
    
    path = [(0,0)]
    remaining_down = (k*n-x-y)//2
    remaining_right = x
    remaining_up = (k*n-x+y)//2

    while remaining_down > 0:
        move_down = min(remaining_down, k)
        remaining_down -= move_down
        remaining_right -= (k-move_down)

        px, py = path[-1]
        cx, cy = px+(k-move_down), py-move_down

        assert (abs(px-cx)+abs(py-cy) == k)
        path.append((cx,cy))

   
    while remaining_right > 0:
        move_right = min(remaining_right, k)
        remaining_right -= move_right
        remaining_up -= (k - move_right)

        px, py = path[-1]
        cx, cy = px+move_right, py+(k-move_right)
        assert (abs(px-cx)+abs(py-cy) == k)
        path.append((cx,cy))
    
    assert remaining_up%k == 0, remaining_up
    while remaining_up > 0:
        move_up = min(remaining_up, k)
        remaining_up -= move_up

        px, py = path[-1]
        cx, cy = px, py+move_up
        assert (abs(px-cx)+abs(py-cy) == k)
        path.append((cx,cy))

    return path[1:]

path = solve()
if path is None:
    print(-1)
else:
    print(len(path))
    for x0, y0 in path:
        if swap_flag:
            x0, y0 = y0, x0
        x1 = x0*x_flip
        y1 = y0*y_flip

        print(x1, y1)