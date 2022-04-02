def isalpha(ch):
    if ord('a') <= ord(ch) <= ord('z'): return True
    if ord('A') <= ord(ch) <= ord('Z'): return True
    return False

def manhat(a,b):
    return abs(a[0]-b[0]) + abs(a[1]-b[1])

def testcase():
    R, C = list(map(int, input().split()))
    grid = []
    curr = ()
    locs = dict()

    for i in range(R):
        line = input()
        grid.append(line)
        for j in range(len(line)):
            if line[j] == '*': curr = (i,j)
            if isalpha(line[j]): locs[line[j]] = (i,j)
    
    ans = 0
    for i in range(26):
        victim = chr(ord('A')+i)
        home = chr(ord('a')+i)
        if not locs.get(victim,-1) == -1:
            ans += manhat(curr, locs[victim])
            curr = locs[victim]
            ans += manhat(curr, locs[home])
            curr = locs[home]
    print(ans)


T = int(input())

for x in range(T):
    testcase()