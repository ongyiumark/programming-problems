import sys
input = sys.stdin.readline

def gcd(a,b):
    if b == 0: return a
    return gcd(b, a%b)

def testcase():
    N = int(input())
    A = [int(x) for x in input().split()]
    M = int(input())
    B = [int(x) for x in input().split()]
    G = gcd(M,N)

    Ag = [[] for i in range(G)]
    Bg = [[] for i in range(G)]

    for i in range(N):
        Ag[i%G].append(A[i])
    for i in range(M):
        Bg[i%G].append(B[i])
    
    ans = 0
    for i in range(G):
        ans = max(max(Ag[i])+max(Bg[i]), ans)
    print(ans)


T = int(input())
for i in range(T):
    testcase()