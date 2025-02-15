n = int(input())
a = list(map(int, input().split()))
b = [None]*n

j = 0
for i in range(n):
    while j < n and 2*a[i] > a[j]:
        j += 1
    b[i] = j

total = 0
for i in range(n):
    total += n-1-b[i]+1

print(total)
