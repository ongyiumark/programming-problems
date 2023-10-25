n = int(input())
words = [input() for _ in range(n)]

def solve(x ,y, dep):
    if x == y:
        return 0
    
    if dep > 50:
        return -float('inf')
    return 1+solve(x, y[1:]+y[0], dep+1)

best = float('inf')
for x in words:
    total = 0
    for y in words:
        res = solve(x, y, 0)
        if res < 0:
            total = -1
            break
        total += res
    
    best = min(best, total)

print(best)