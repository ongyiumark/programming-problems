n = int(input())
mod = 10**9+7
for _ in range(n):
    a, b = [int(x) for x in input().split()]
    print(pow(a,b,mod))