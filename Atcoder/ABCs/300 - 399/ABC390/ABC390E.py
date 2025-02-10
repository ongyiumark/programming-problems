N, X = list(map(int, input().split()))

vitamin = [[],[],[]]
for i in range(N):
    v, a, c = list(map(int, input().split()))
    vitamin[v-1].append((a,c))

max_units = [[0 for _ in range(X+1)] for _ in range(3)]
for v in range(3):
    for a, c in vitamin[v]:
        ntable = [0 for _ in range(X+1)]
        for cal in range(X+1):
            ntable[cal] = max(ntable[cal], max_units[v][cal])
            if cal >= c:
                ntable[cal] = max(ntable[cal], max_units[v][cal-c]+a)
        max_units[v] = ntable


def possible(min_units):
    min_cals = []
    for v in range(3):
        lo, hi = 0, X
        calories = float("inf")
        while lo <= hi:
            mid = hi - (hi-lo)//2
            if max_units[v][mid] >= min_units:
                calories = mid
                hi = mid-1
            else:
                lo = mid+1
        min_cals.append(calories)
    
    return sum(min_cals) <= X


# binary search answer
lo, hi = 0, 10**9+5
ans = 0
while lo <= hi:
    mid = hi - (hi-lo)//2
    if possible(mid):
        ans = mid
        lo = mid+1
    else:
        hi = mid-1

print(ans)