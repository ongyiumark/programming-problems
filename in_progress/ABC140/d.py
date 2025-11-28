n, k = list(map(int, input().split()))
s = input()

happy = 0
for i in range(n):
    if i != 0:
        if s[i] == 'L' and s[i-1] == 'L':
            happy += 1
    if i != n-1:
        if s[i] == 'R' and s[i+1] == 'R':
            happy += 1

rl_count = 0
for i in range(n-1):
    if s[i] == 'R' and s[i+1] == 'L':
        rl_count += 1

x = rl_count
# LXXXXXR -> 1    
# LXXXXXL -> 0
# RXXXXXR -> 0
# RRRRLLL -> 1
y = (s[0] == 'L') and (s[n-1] == 'R')
if s[0] == 'R' and s[n-1] == 'L':
    y += 1
    if x > 0:
        x -= 1


print(happy + 2*min(x,k)+max(0,min(k-x,y)))