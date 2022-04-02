import sys
input = sys.stdin.readline

a, b = "", ""
stored = [0 for i in range(10)]
rep = 0
n, m = 0, 0

def valid(num):
    if num == 0:
        return True
    curr = [0 for i in range(10)]
    
    if rep*(num-1)+n > m: return False

    for i in range(num-1):
        for j in range(rep):
            if stored[ord(b[j])-ord('0')] == curr[ord(b[j])-ord('0')]: return False
            curr[ord(b[j])-ord('0')] += 1
    
    for i in range(n):
        if stored[ord(b[i])-ord('0')] == curr[ord(b[i])-ord('0')]: return False
        curr[ord(b[i])-ord('0')] += 1
    return True

def testcase():
    global a,b, n, m, rep, stored
    a, b = input().split()
    stored = [0 for i in range(10)]
    for ch in a:
        stored[ord(ch)-ord('0')] += 1
            
    n = len(b)
    m = len(a)
    rep = n
    for i in range(1,n):
        ans = True
        for j in range(n-i):
            ans &= (b[j] == b[i+j])
        if ans:
            rep = i
            break
    lo = 0
    hi = 10**5
    ans = -1
    while lo <= hi:
        mid = hi - (hi-lo)//2
        if valid(mid):
            ans = mid
            lo = mid+1
        else: hi = mid-1

    print(ans)

T = int(input())
for i in range(T):
    testcase()
