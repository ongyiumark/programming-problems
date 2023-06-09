import sys
input = sys.stdin.readline


def inversions(X, l, r):
    if r < l:
        return 0, []
    if r == l:
        return 0, [X[l]]

    mid = (l+r)//2
    a, left = inversions(X, l, mid)
    b, right = inversions(X, mid+1, r)

    left_n = len(left)
    right_n = len(right)
    c_left, c_right = 0, 0
    res = []
    total = 0
    while c_left < left_n or c_right < right_n:
        if c_right >= right_n:
            res.append(left[c_left])
            c_left += 1
            continue
        if c_left >= left_n:
            res.append(right[c_right])
            c_right += 1
            total += left_n-c_left
            continue

        if left[c_left] <= right[c_right]:
            res.append(left[c_left])
            c_left += 1
        else:
            res.append(right[c_right])
            c_right += 1 
            total += left_n-c_left

    return total+a+b, res           

def testcase():
    n = int(input())
    A = [int(x) for x in input().split()]
    B = [int(x) for x in input().split()]

    ids = {x: i for i,x in enumerate(A)}
    X = [ids[x] for x in B]
    
    ans, sortedX = inversions(X, 0, n-1)
    print(ans)


T = int(input())
for _ in range(T):
    testcase()