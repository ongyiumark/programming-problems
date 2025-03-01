n, k = list(map(int, input().split()))
s = input()

L = []
R = []

l_cnt, r_cnt = (s[0]=="L"), (s[0]=="R")
for i in range(1, n):
    if s[i] == "L":
        l_cnt += 1
        R.append(r_cnt)
        r_cnt = 0
    else:
        r_cnt += 1
        L.append(l_cnt)
        l_cnt = 0

if l_cnt > 0:
    L.append(l_cnt)
if r_cnt > 0:
    R.append(r_cnt)

L.sort(reverse=True)
R.sort(reverse=True)

print(max(sum(L)-len(L)+sum(R[:min(k+1, len(R))]), sum(R)-len(R)+sum(L[:min(k, len(L))])))