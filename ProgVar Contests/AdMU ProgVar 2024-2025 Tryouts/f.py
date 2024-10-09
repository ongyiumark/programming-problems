n, m = [int(x) for x in input().split()]
schools = [int(input()) for _ in range(m)]
vals = [0]*len(schools)

i = 0
while sum(schools) > 0 and n > 0:
    index = i%m
    if schools[index] == 0:
        i += 1
        continue
    schools[index] -= 1
    vals[index] += 1
    n -= 1
    i += 1

for v in vals:
    print(v)
