n = int(input())
b = list(map(int, input().split()))

total = b[0]
for i in range(1, n-1):
    total += min(b[i], b[i-1])
total += b[n-2]
print(total)