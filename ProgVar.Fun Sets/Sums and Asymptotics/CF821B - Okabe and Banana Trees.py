m, b = [int(x) for x in input().split()]

def solve(x, y):
    return (y+1)*x*(x+1)//2 + (x+1)*y*(y+1)//2

best = 0
for r in range(0,b+1):
    best = max(best, solve(b-r, m*r))
    
print(best)