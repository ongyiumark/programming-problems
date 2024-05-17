for _ in range(int(input())):
  a,b,c = [int(x) for x in input().split()]
  if c < 0:
    print("CURVE DOWN")
  elif c > 0:
    print("CURVE UP")
  else:
    print("NO CURVE")
