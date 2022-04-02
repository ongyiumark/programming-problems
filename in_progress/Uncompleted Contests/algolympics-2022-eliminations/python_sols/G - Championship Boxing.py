def get_range(a, b, c, d):
    return cumsum[c][d]-cumsum[a-1][d]-cumsum[c][b-1]+cumsum[a-1][b-1]

def testcase():
    R, C = list(map(int, input().split()))
    global cumsum
    cumsum = [[0]*(C+2) for i in range(R+2)]
    B = [[False]*(C+2) for i in range(R+2)]
    grid = []
    grid.append('.'*(C+2))
    for i in range(R):
        line = input()
        grid.append('.'+line+'.')
    grid.append('.'*(C+2))
    
    for i in range(R+2):
        for j in range(C+2):
            cumsum[i][j] = int(grid[i][j] == '#')
            if i == 0 and j == 0: pass
            elif i == 0: cumsum[i][j] += cumsum[i-1][j]
            elif j == 0: cumsum[i][j] += cumsum[i][j-1]
            else: cumsum[i][j] += cumsum[i-1][j] + cumsum[i][j-1] - cumsum[i-1][j-1]
    
    ans = 0
    best = (0,0,0)
    for i in range(1,R+1):
        for j in range(1,C+1):
            for k in range(2,min(R,C)+1):
                if i+k > R: break
                if j+k > C: break
                
                if get_range(i,j,i+k,j+k)-get_range(i+1,j+1,i+k-1,j+k-1) == 0:
                    nans = get_range(i,j, i+k,j+k)
                    if nans > ans:
                        ans = nans
                        best = (i,j,k)

    if ans == 0:
        print("NO")
        for i in range(1,R+1):
            for j in range(1,C+1):
                print(grid[i][j],end="")
            print()
    else:
        print(ans)
        i, j, k = best
        for x in range(i,i+k+1):
            B[x][j] = B[x][j+k] = True
        for x in range(j,j+k+1):
            B[i][x] = B[i+k][x] = True
        for x in range(1,R+1):
            for y in range(1,C+1):
                if B[x][y]: print('B',end="")
                else: print(grid[x][y],end="")
            print()
        


T = int(input())

for i in range(T):
    testcase()