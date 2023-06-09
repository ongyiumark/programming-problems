n = int(input())
X = [int(x) for x in input().split()]

best = float('inf')
for P in range(1, 101):
    total = 0
    for x in X:
        total += pow(x-P, 2)

    best = min(total, best)

print(best)