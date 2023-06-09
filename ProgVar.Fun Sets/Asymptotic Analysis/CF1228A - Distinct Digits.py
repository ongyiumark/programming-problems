l, r = [int(x) for x in input().split()]

for x in range(l, r+1):
    str_x = str(x)
    sz = len(str_x)
    if sz == len(set(list(str_x))):
        print(x)
        exit(0)

print(-1)