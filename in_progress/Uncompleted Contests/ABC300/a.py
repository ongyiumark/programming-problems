n, a, b = [int(x) for x in input().split()]
C = [int(x) for x in input().split()]
for i, x in enumerate(C):
  if x == a + b:
    print(i+1)