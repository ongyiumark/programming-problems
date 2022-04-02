def testcase():
    R, C = list(map(int,input().split()))
    ans = [['R']*C for i in range(R)]
    for i in range(R):
        line = input()
        for j in range(C):
            if line[j] == 'B':
                ans[i][j] = 'B'
    input()
    for i in range(R):
        line = input()
        for j in range(C):
            if line[j] == 'G':
                ans[i][j] = 'G'

    for i in range(R):
        print(''.join(ans[i]))


T = int(input())

for i in range(T):
    testcase()
    if i != T-1: print()