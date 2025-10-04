n = int(input())
a = list(map(int, input().split()))

total = 0
i, j = 0, 1
while i < n:
    while j < n and a[j-1] < a[j]:
        j += 1
    m = j-i
    total += m*(m+1)//2

    i = j
    j += 1
print(total)