def testcase():
    N, K = list(map(int,input().split()))
    enlightened = [False]*N
    enlightened[0] = True
    for i in range(K):
        u, v = list(map(int,input().split()))
        u -= 1
        v -= 1
        if enlightened[u]|enlightened[v]:
            enlightened[u] = enlightened[v] = True
        
    print(' '.join([str(i+1) for i,x in enumerate(enlightened) if x]))



T = int(input())

for x in range(T):
    testcase()