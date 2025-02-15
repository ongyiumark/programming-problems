n = int(input())
a = list(map(int, input().split()))
b = [None]*n

j = 0
for i in range(n):
    while j < n and 2*a[i] > a[j]:
        j += 1
    
    b[i] = j-i

result = 0
max_inc = -float("inf")
for i in range(n//2):
    max_inc = max(max_inc, b[i])
    if i+max_inc <= n-1:
        result = i+1

print(result)