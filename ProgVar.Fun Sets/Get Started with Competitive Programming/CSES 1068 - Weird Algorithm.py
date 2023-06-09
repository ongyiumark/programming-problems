def collatz(n):
    if n&1: return 3*n+1
    return n//2

n = int(input())
res = [n]
while n != 1:
    n = collatz(n)
    res.append(n)

print(' '.join(map(str,res)))