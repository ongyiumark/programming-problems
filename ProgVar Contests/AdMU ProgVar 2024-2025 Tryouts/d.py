w, p = [int(x) for x in input().split()]
partitions = [0]+[int(x) for x in input().split()]+[w]
res = set()

for x in partitions:
    for y in partitions:
        if x >= y: continue
        res.add(y-x)

print(" ".join(map(str, sorted(list(res)))))
