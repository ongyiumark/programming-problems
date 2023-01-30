import sys
input = sys.stdin.readline

n = int(input())
s = list(input())

i, j = 0, n-1
cnt = 0
while i < j:
    while i < j and s[i] == 'R':
        i += 1
    while i < j and s[j] == 'W':
        j -= 1
    if not i < j:
        break
    s[i], s[j] = s[j], s[i]
    cnt += 1
print(cnt)