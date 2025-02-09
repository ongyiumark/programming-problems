n, k = [int(x) for x in input().split()]

for _ in range(k):
    n_str = list(str(n))
    n = int(''.join(sorted(n_str)[::-1]))-int(''.join(sorted(n_str)))

print(n)