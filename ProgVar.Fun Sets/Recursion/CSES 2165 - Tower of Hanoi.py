ans = []

def solve(fr, to, space, k):
    if k == 1:
        ans.append((fr, to))
        return 
    if k == 2:
        ans.append((fr, space))
        ans.append((fr, to))
        ans.append((space, to))
        return

    solve(fr, space, to, k-1)
    ans.append((fr, to))
    solve(space, to, fr, k-1)

n = int(input())
solve(1, 3, 2, n)

print(len(ans))
for u, v in ans:
    print(u, v)