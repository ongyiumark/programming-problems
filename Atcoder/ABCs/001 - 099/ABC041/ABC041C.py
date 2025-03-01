n = int(input())
a = list(map(int, input().split()))
b = [(x,i+1) for i,x in enumerate(a)]
b.sort(reverse=True)

for x in b:
    print(x[1])
