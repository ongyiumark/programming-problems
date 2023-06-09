K, S = [int(x) for x in input().split()]

total = 0
for x in range(K+1):
    for y in range(K+1):
        if x + y <= S and S-x-y <= K:
            total += 1
print(total)
