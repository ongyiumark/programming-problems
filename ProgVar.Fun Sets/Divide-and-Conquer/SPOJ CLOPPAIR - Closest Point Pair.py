import sys
input = sys.stdin.readline

n = int(input())
points = []
for i in range(n):
    a, b = [int(x) for x in input().split()]
    points.append((a,b,i))

# sort points by x
points.sort()

def dist(a, b):
    return ((a[0]-b[0])**2 + (a[1]-b[1])**2)**0.5

def solve(p, l, r):
    sz = r-l+1
    
    # brute force if small
    if sz <= 3:
        best = float('inf')
        aidx, bidx = None, None
        for i in range(l, r+1):
            for j in range(i+1, r+1):
                tmp = dist(p[i], p[j])
                if tmp <= best:
                    best, aidx, bidx = tmp, p[i][2], p[j][2]
        
        if bidx < aidx:
            aidx, bidx = bidx, aidx
        return aidx, bidx, best

    # divide and conquer
    mid = (l+r)>>1
    l_aidx, l_bidx, dl = solve(p, l, mid)
    r_aidx, r_bidx, dr = solve(p, mid+1, r)

    # save index
    if dl <= dr:
        aidx, bidx = l_aidx, l_bidx
    else:
        aidx, bidx = r_aidx, r_bidx
    d = min(dl, dr)

    # make slit of width d
    leftp, rightp = [], []
    for i in range(l, r+1):
        if abs(p[i][0]-p[mid][0]) < d and i <= mid:
            leftp.append(p[i])
        if abs(p[i][0]-p[mid+1][0]) < d and i >= mid+1:
            rightp.append(p[i])

    # sort by y coordinate
    leftp.sort(key = lambda p : p[1])
    rightp.sort(key = lambda p : p[1])

    lsz = len(leftp)
    rsz = len(rightp)
    best = d

    for point in leftp:
        x, y, i = point

        # binary search for point such that y-d <= p[1] <= y+d
        lo, hi = 0, rsz-1
        l_ans = rsz
        while lo <= hi:
            mid = hi - (hi - lo)//2
            if y-d <= rightp[mid][1]:
                l_ans = mid
                hi = mid-1
            else:
                lo = mid+1

        r_ans = -1
        lo, hi = 0, rsz-1
        while lo <= hi:
            mid = hi - (hi - lo)//2
            if rightp[mid][1] <= y+d:
                r_ans = mid
                lo = mid+1
            else:
                hi = mid-1
        
        if r_ans < l_ans:
            continue
        
        for j in range(l_ans, r_ans+1):
            tmp = dist(point, rightp[j])
            if tmp <= best:
                best, aidx, bidx = tmp, point[2], rightp[j][2]
    

    if bidx < aidx:
        aidx, bidx = bidx, aidx
    return aidx, bidx, best

a, b, d = solve(points, 0, n-1)
print(f"{a} {b} {d:.6f}")
