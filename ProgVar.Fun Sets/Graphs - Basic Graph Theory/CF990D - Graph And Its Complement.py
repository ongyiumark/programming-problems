n, a, b = [int(x) for x in input().split()]

flag = False
if b > a:
    a, b = b, a
    flag = True

def possible(n, a, b):
    if a > n:
        return False
    
    if a > 1:
        return b == 1
    
    if a == 1:
        return n >= 4 or n == 1

if possible(n, a, b):
    print("YES")
    mat = [['0']*n for _ in range(n)]

    for i in range(n-a):
        mat[i][i+1] = mat[i+1][i] = '1'
    
    if flag:
        for i in range(n):
            for j in range(n):
                if i == j: continue
                if mat[i][j] == '0':
                    mat[i][j] = '1'
                else:
                    mat[i][j] = '0'
    
    for row in mat:
        print(''.join(row))
else:
    print("NO")
