n, l, r, x = [int(y) for y in input().split()]
c = [int(y) for y in input().split()]

def verify(problems):
    return (len(problems) >= 2) and (l <= sum(problems) <= r) and (max(problems)-min(problems) >= x)
    
def solve(i, problems):
    if i == n:
        if len(problems) < 2:
            return 0
        return verify(problems)

    total = solve(i+1, problems)
    problems.append(c[i])
    total += solve(i+1, problems)
    problems.pop()

    return total

problems = []
print(solve(0, problems))