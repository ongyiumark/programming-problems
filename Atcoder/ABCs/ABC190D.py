# Each odd divisor of n contributes to 2 sequences

n = int(input())

k = 1
ans = 0
while k*k <= n:
    if n%k == 0:
        if k&1:
            ans += 1
        
        if (n//k)&1:
            ans += 1

        if k*k == n and k&1:
            ans -= 1

    k += 1

print(2*ans)