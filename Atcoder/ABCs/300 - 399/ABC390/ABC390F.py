N = int(input())
A = list(map(int, input().split()))

indices = [set() for _ in range(N+1)]
for i,x in enumerate(A):
    indices[x].add(i+1)

def calculate_pairs(idxs):
    idxs = set(idxs)
    idxs.add(0)
    idxs.add(N+1)

    idxs = sorted(list(idxs))
    total = 0
    for i in range(1, len(idxs)):
        a = idxs[i-1]
        b = idxs[i]
        total += (b-a)*(b-a-1)//2
    return total

ans = 0
for x in range(1, N+1):
    pairs_without_x_minus_one = calculate_pairs(indices[x-1])
    pairs_without_x_x_minus_one = calculate_pairs(indices[x-1].union(indices[x]))
    pairs = pairs_without_x_minus_one - pairs_without_x_x_minus_one
    ans += pairs
print(ans)
