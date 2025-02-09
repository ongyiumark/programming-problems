n, q = [int(x) for x in input().split()]
pigeons_in_nest = [1]*n
home_of_pigeon = [i for i in range(n)]


count = 0
for _ in range(q):
    query = input()
    if query[0] == "2":
        print(count)
    else:
        _, p, h = [int(x) for x in query.split()]
        p -= 1
        h -= 1
        pigeons_in_nest[home_of_pigeon[p]] -= 1
        if pigeons_in_nest[home_of_pigeon[p]] == 1:
            count -= 1
        home_of_pigeon[p] = h
        pigeons_in_nest[h] += 1
        if pigeons_in_nest[h] == 2:
            count += 1