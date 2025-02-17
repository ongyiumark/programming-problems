n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

total = 0
for i in range(n):
    defeated_here = min(a[i], b[i])
    a[i] -= defeated_here
    b[i] -= defeated_here

    defeated_there = min(a[i+1], b[i])
    a[i+1] -= defeated_there
    b[i] -= defeated_there

    total += defeated_here + defeated_there

print(total)