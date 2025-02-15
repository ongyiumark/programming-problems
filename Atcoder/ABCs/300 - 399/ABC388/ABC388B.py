n, d = list(map(int, input().split()))
snakes = [None]*n
for i in range(n):
    snakes[i] = tuple(map(int, input().split()))

for k in range(1, d+1):
    print(max([t*(l+k) for t,l in snakes]))

