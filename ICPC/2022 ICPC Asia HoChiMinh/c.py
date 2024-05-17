n = int(input())
inp = [
  [int(x) for x in input().split()],
  [int(x) for x in input().split()]
]
target = [inp[1][:], inp[0][:]]

prev = {}
q = [[inp[0][:], inp[1][:]]]
tmp = []
while q:
  for cur in q:
    zero = [-1, -1]
    zero[0] = 0 if 0 in cur[0] else 1
    zero[1] = cur[zero[0]].index(0)
    other = (zero[0]+1) % 2

    for i, val in enumerate(cur[other]):
      push = [cur[0][:], cur[1][:]]
      push[zero[0]][zero[1]], push[other][i] = push[other][i], push[zero[0]][zero[1]]
      tupled = (tuple(push[0]), tuple(push[1]))
      if tupled in prev:
        continue
      prev[tupled] = (tuple(cur[0]), tuple(cur[1]))
      tmp.append(push)
      if push == target:
        break
    if (tuple(target[0]), tuple(target[1])) in prev:
      break
  if (tuple(target[0]), tuple(target[1])) in prev:
    break
  tmp, q = q, tmp
  tmp = []


cur = (tuple(target[0]), tuple(target[1]))
while cur != (tuple(inp[0]), tuple(inp[1])):
  print(*cur, sep='\n')
  print()
  cur = prev[cur]
print(*cur, sep='\n')
print()