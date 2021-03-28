from decimal import Decimal
from math import comb

def f(n):
    total = Decimal(0)
    for i in range(100,n+1):
        total += Decimal(comb(n,i))*Decimal(0.995**i)*Decimal(0.005**(n-i))
    
    return total

for i in range(100, 200):
    print(i, f(i))