n = int(input())
p = list(map(int, input().split()))

def is_sorted(p):
    n = len(p)
    for i in range(1, n):
        if p[i-1] > p[i]:
            return False

    return True

possible = is_sorted(p)
for i in range(n):
    for j in range(i+1, n):
        p[i], p[j] = p[j], p[i]
        if is_sorted(p):
            possible = True
        p[i], p[j] = p[j], p[i]

print("YES" if possible else "NO")