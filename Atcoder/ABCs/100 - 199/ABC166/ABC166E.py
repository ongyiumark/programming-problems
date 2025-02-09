n = int(input())
a = [int(x) for x in input().split()]

s = dict()
cnt = 0
for i,x in enumerate(a):
    cnt += s.get(i-x, 0)
    s[i+x] = s.get(i+x, 0) + 1
print(cnt)