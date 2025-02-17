n = int(input())

b = 1
digits = 0
total = 0
while b <= n:
    nb = b*10
    digits += 1

    if digits%2 == 1:
        total += min(nb,n+1)-b
    
    b = nb

print(total)
