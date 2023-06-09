grid = [[int(x) for x in input().split()] for _ in range(9)]

val = True

# rows
for row in grid:
    if len(set(row)) < 9:
        val = False

# cols
for col in zip(*grid):
    if len(set(col)) < 9:
        val = False
    
# boxes
boxes = [[[False]*9 for j in range(3)] for i in range(3)]
for i in range(9):
    for j in range(9):
        boxes[i//3][j//3][grid[i][j]-1] = True

for i in range(3):
    for j in range(3):
        if not all(boxes[i][j]):
            val = False

# result
print("VALID") if val else print("INVALID")