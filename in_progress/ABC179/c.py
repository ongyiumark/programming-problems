n = int(input())

total = 0
for c in range(1, n):
    p = n-c

    div = 0
    d = 1
    while d*d <= p:
        if p%d == 0:
            div += 2
        if d*d == p:
            div -= 1

        d += 1
    
    total += div

print(total)