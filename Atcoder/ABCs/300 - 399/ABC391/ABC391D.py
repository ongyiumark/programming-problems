n, w = [int(x) for x in input().split()]
blocks = list()

blocks_in_column = [list() for _ in range(w)] 
for i in range(n):
    blocks.append([int(x) for x in input().split()])
    x, y = blocks[-1]

    blocks_in_column[x-1].append(i)

shortest_column = 0
least_blocks = float("inf")
for i in range(w):
    blocks_in_column[i] = blocks_in_column[i][::-1]
    if len(blocks_in_column[i]) < least_blocks:
        least_blocks = len(blocks_in_column[i])
        shortest_column = i

block_delete_time = [float("inf") for _ in range(n)]
blocks_removed = 0
while blocks_removed < n and len(blocks_in_column[shortest_column]) > 0:
    highest = 0
    for i in range(w):
        first_block = blocks_in_column[i][-1]
        highest = max(highest, blocks[first_block][1])
    
    for i in range(w):
        first_block = blocks_in_column[i][-1]
        block_delete_time[first_block] = highest
        blocks_in_column[i].pop()


q = int(input())

for _ in range(q):
    t, a = [int(x) for x in input().split()]
    a -= 1
    
    if t >= block_delete_time[a]:
        print("No")
    else:
        print("Yes")
