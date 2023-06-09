n = int(input())

def compute(n):
    return n*(n+1)//2

total = 0
for _ in range(n):
    a, b = [int(x) for x in input().split()]
    total += compute(b)-compute(a-1)

print(total)