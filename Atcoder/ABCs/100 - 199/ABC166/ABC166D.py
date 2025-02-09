x = int(input())

s = set()
fifth_root = dict()
for i in range(-1000, 1000, 1):
    s.add(i**5)
    fifth_root[i**5] = i


val = 0
for ss in s:
    if (ss + x) in s:
        print(fifth_root[ss+x], fifth_root[ss])
        break
    