n = int(input())
v = list(map(int, input().split()))
v.sort(reverse=True)

total = 0
for i in range(n-1):
    total += v[i]/2**(i+1)

total += v[n-1]/2**(n-1)
print(f"{total:.20f}")