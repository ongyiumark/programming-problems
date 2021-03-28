import math
mod = int(10**24+7)
primes = [2,3,5,7,11,13,17,19,23,29]

def solve(n):
    factors = {}
    for i in range(2,int(math.sqrt(n)+1)):
        if n % i == 0: factors[i] = 0
        while n % i == 0:
            factors[i]+=1
            n //= i
    if n > 1: factors[n] = 1
    print(factors)
        

for _ in range(int(input())):
    n = int(input())
    solve(n)