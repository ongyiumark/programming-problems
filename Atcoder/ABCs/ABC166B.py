n, k = [int(x) for x in input().split()]
a = [0]*n
for _ in range(k):
    d = int(input())
    b = [int(x)-1 for x in input().split()]
    for bb in b:
        a[bb] += 1

print(sum(x == 0 for x in a))