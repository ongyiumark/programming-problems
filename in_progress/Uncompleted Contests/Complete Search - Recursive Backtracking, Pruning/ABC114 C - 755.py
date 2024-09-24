s = input()

def solve(i, started, is_lower, has_seven, has_five, has_three):
    if i >= len(s):
        return has_seven and has_five and has_three

    total = 0
    if is_lower:
        for d in [0,3,5,7]:
            if started and d == 0: 
                continue

            total += solve(i+1, started or d > 0, is_lower, d==7 or has_seven, d==5 or has_five, d==3 or has_three)
    else:
        for d in [0,3,5,7]:
            if started and d == 0:
                continue
            if d > int(s[i]):
                continue
            total += solve(i+1, started or d > 0, d < int(s[i]), d==7 or has_seven, d==5 or has_five, d==3 or has_three)
    return total

print(solve(0, False, False, False, False, False))