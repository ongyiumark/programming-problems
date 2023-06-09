from itertools import product

X = int(input())
for a, b in product(range(-1000,1000), repeat=2):
    if pow(a,5)-pow(b,5) == X:
        print(a,b)
        exit(0)