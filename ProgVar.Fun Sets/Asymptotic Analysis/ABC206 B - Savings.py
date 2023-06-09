n = int(input())

for x in range(1,n+1):
    if x*(x+1)//2 >= n:
        print(x)
        exit(0)