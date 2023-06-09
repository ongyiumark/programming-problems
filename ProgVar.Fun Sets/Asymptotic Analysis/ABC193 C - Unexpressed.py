n = int(input())

nums = []
for a in range(2, n+1):
    if a*a > n:
        break
    for b in range(2, n+1):
        res = pow(a,b)
        if res > n:
            break
        nums.append(res)

print(n-len(set(nums)))