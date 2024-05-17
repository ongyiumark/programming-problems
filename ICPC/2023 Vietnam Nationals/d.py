for _ in range(int(input())):
  n = int(input())
  arr = [int(x) for x in input().split()]

  i , j = 0, 0
  for x in range(1, len(arr)):
    if x in check:
      ans += l*(l+1)//2
      check = set()
      check.add(arr[x])
    else:
      check.add(arr[x])
      l += 1
  print(ans)