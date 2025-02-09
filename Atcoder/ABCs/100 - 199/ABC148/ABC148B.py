n = int(input())
s,t = input().split()

print(''.join([x[i] for i in range(n) for x in [s,t]]))