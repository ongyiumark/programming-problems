[x, y] = [int(a) for a in input().split()]

if (y-2*x)%2 == 1:
    print("No")
    exit(0)

b = (y-2*x)//2
a = x-b

if a >= 0 and b >= 0:
    print("Yes")
else:
    print("No")