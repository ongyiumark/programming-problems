n = int(input())
ans = (n+1)//2 
if n&1:
    ans *= -1
print(ans)