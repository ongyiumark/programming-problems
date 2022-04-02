T = int(input())

for x in range(T):
    R,C = list(map(int, input().split()))
    ans = True
    for i in range(R):
        line = input()
        if line.count('X') == C: ans = False

    print("DIPLOMACY!") if ans else print("FIREWORKS!")