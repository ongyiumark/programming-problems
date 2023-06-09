s = list(input())
k = len(s)

best = float('inf')
for i in range(k):
    s[0], s[i] = s[i], s[0]

    for mask in range(1<<(k-1)):
        res = [s[0]]
        for j in range(k-1):
            if mask&(1<<j):
                res.append(s[j+1])
    
        if sum([int(x) for x in res])%3 == 0:
            best = min(best, k-len(res))

    s[0], s[i] = s[i], s[0]

if best < float('inf'):
    print(best)
else:
    print(-1)