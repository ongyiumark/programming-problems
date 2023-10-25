from itertools import product

n, m = [int(x) for x in input().split()]

count = 0
for a, b in product(range(max(n,m)+1), repeat=2):
    count += (a*a+b == n) and (a+b*b == m)

print(count)