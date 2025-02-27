import sys
input = lambda : sys.stdin.readline().strip()

s = input()
t = input()

n = len(s)
next_index = [None]*n

state = [None]*26
for i in range(2*n-1, -1, -1):
    if i < n:
        next_index[i] = tuple(state)
    idx = ord(s[i%n])-ord("a")
    state[idx] = i%n

success = True

j = 0
revolutions = 0
for i in range(s[0]==t[0], len(t)):
    idx = ord(t[i])-ord("a")
    nj = next_index[j][idx]
    if nj is None:
        success = False
        break
    
    if nj <= j:
        revolutions += 1
    j = nj

print(j+revolutions*n+1 if success else -1)