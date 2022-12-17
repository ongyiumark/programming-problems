t = int(input())

for _ in range(t):
    s = input()
    b = bin(int(s,8))[2:]
    n = len(b)
    if n < 19:
        b = "0"*(19-n) + b
    
    assert(len(b) == 19)
    
    played = b[-9:][::-1]
    xo = b[-18:-9][::-1]
    
    grid = [[0 for i in range(3)] for j in range(3)]
    for i in range(3):
        for j in range(3):
            k = 3*i+j
            if played[k] == '0':
                grid[i][j] = 2
            else:
                grid[i][j] = int(xo[k])
    
    winner = -1
    # rows
    for i in range(3):
        val = True
        for j in range(2):
            val &= (grid[i][j+1]==grid[i][j] and grid[i][j] != 2) 
        if val:
            winner = grid[i][0]


    # cols
    for j in range(3):
        val = True
        for i in range(2):
            val &= (grid[i+1][j]==grid[i][j] and grid[i][j] != 2) 
        if val:
            winner = grid[0][j]

    # diags
    val = True
    for i in range(2):
        val &= (grid[i+1][i+1]==grid[i][i] and grid[i][i] != 2) 
    if val:
        winner = grid[0][0]
    
    grid = grid[::-1]
    val = True
    for i in range(2):
        val &= (grid[i+1][i+1]==grid[i][i] and grid[i][i] != 2) 
    if val:
        winner = grid[0][0]
    
    if winner != -1:
        print(f'{"O" if winner == 0 else "X"} wins')
        continue
    
    if int(played,2) == 2**9-1:
        print("Cat's")
    else:
        print("In progress")

