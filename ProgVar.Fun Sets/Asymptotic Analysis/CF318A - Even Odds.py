[n, k] = [int(x) for x in input().split()]
odds = (n+1)//2
evens = n//2

if k <= odds:
    print(2*k-1)
else:
    print(2*(k-odds))