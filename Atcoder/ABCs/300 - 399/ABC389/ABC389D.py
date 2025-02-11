R = int(input())

def find_max_y(x):
    lo, hi = 1, R
    ans = 0
    while lo <= hi:
        mid = hi-(hi-lo)//2
        if x**2 + (mid-0.5)**2 <= R**2:
            ans = mid
            lo = mid+1
        else:
            hi = mid-1
    return ans

res = 0
for x in range(-R, R-1):
    y1 = find_max_y(x+0.5)
    y2 = find_max_y(x+1.5)
    y = min(y1, y2)
    res += 2*y-1

print(res)
