t = int(input())
for _ in range(t):
  n, d = [int(x) for x in input().split()]
  ans = 0
  for x in range(62):
    if (d+1)**x >= n:
      ans = x
      break
  print(ans)
