n = int(input())
h = list(map(int,input().split()))

best_count = 0
count = 0
for i in range(1, n):
    if h[i] <= h[i-1]:
        count += 1
    else:
        count = 0
    best_count = max(best_count, count)
print(best_count)