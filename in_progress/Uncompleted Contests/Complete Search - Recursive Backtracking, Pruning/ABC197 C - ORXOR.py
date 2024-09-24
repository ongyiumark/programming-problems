n = int(input())

A = [int(x) for x in input().split()]

best = float('inf')
def solve(i, c_or, c_xor):
    global best
    if i == n:
        tmp = c_xor^c_or
        best = min(best, tmp)
        return

    solve(i+1, c_or|A[i], c_xor)
    solve(i+1, A[i], c_xor^c_or)

solve(1, A[0], 0)
print(best)