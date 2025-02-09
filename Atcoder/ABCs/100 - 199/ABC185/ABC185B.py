n, m, t = [int(x) for x in input().split()]

charge = n
time = 0
val = True
for _ in range(m):
    a,b = [int(x) for x in input().split()]

    charge -= (a-time)
    time = a
    if charge <= 0:
        val = False
        charge = 0
    
    charge += (b-time)
    time = b
    if charge >= n:
        charge = n

charge -= (t-time)
if charge <= 0:
    val = False
    charge = 0

print("Yes") if val else print("No")