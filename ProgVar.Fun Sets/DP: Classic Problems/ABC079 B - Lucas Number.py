n = int(input())

L = [2, 1]+[0]*(n-1)
for i in range(2, n+1):
    L[i] = L[i-1]+L[i-2]
print(L[n])
