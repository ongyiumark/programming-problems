import sys
input = sys.stdin.readline

n, k = [int(x) for x in input().split()]
print(len([x for _ in range(n) if (x:=int(input())) % k == 0]))