n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
c = list(map(int,input().split()))

total = b[a[0]-1]
for i in range(1, n):
    total += b[a[i]-1]
    if a[i] == a[i-1]+1:
        total += c[a[i-1]-1]

print(total)