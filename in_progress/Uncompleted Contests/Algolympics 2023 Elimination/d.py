from itertools import permutations

t = int(input())

for _ in range(t):
    c = int(input())
    s = input().rstrip()

    chars = dict()
    for ch in s:
        if ch not in '+-/*=':
            chars[ch] = 0
    
    perms = sorted(list(permutations([i for i in range(10)], c)))
    keys = sorted(list(chars.keys()))

    for perm in perms:
        for i, key in enumerate(keys):
            chars[key] = perm[i]
    
        ns = []
        op = '*'
        for ch in s:
            if ch in '+-*/':
                ns.append(ch)
                op = ch
            elif ch == '=':
                ns.append('=')
            else:
                ns.append(str(chars[ch]))
        
        tmp = ''.join(ns)
        a, b = tmp.split(op)
        b, c = b.split('=')

        a = str(int(a))
        b = str(int(b))
        c = str(int(c))

        if int(a) == 0 or int(b) == 0 or int(c) == 0:
            continue

        if op == '/':
            op = '//'

        ans = eval(a + op + b + "==" + c)

        if ans:
            for key in keys:
                print(key, chars[key])
            break

        
