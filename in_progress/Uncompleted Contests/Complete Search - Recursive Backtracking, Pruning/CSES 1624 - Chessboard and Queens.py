grid = [input() for _ in range(8)]

row = [0]*8
col = [0]*8
diag_up = [0]*15
diag_down = [0]*15

def verify():
    for x in row+col+diag_up+diag_down:
        if x > 1:
            return False
    return True

def solve(i):
    if i == 8:
        return verify()

    count = 0
    for j in range(8):
        if grid[i][j] == '*':
            continue
        if col[j] == 1 or diag_up[i+j] == 1 or diag_down[i-j+7] == 1:
            continue
        
        row[i] += 1
        col[j] += 1
        diag_up[i+j] += 1
        diag_down[i-j+7] += 1

        count += solve(i+1)

        row[i] -= 1
        col[j] -= 1
        diag_up[i+j] -= 1
        diag_down[i-j+7] -= 1
    
    return count

print(solve(0))