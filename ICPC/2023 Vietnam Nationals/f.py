import sys
input = sys.stdin.readline
for _ in range(int(input())):
  s = input()
  pref = [(0,0,0) for _ in range(len(s)+1)]
  l = len(s)
  for i, x in enumerate(s):
    a,b,c = pref[i]
    if x == "R":
      a += 1
    elif x == "P":
      b += 1
    else:
      c += 1
    pref[i+1] = (a,b,c)
  
  ans = int(-1e9)
  best_k = 0
  for k in range(2, l + 1):
    temp = 0
    for pos in range(0, len(s),k):
      a = pref[min(pos+k,l)][0] - pref[pos][0]
      b = pref[min(pos+k,l)][1] - pref[pos][1]
      c = pref[min(pos+k,l)][2] - pref[pos][2]
      temp += max(a,b,c)
    if ans < temp:
      ans = temp
      best_k = k
  print(best_k)
    
