from itertools import combinations

iter = 0
while True:
    line = input()
    if line == "0":
        break

    if iter > 0:
        print()
    line = line.split()
    k = int(line[0])
    S = [int(x) for x in line[1:]]

    result = list(combinations(S, 6))
    for res in result:
        print(*res)
    
    iter += 1

