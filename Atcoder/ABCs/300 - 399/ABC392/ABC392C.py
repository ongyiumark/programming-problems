N = int(input())
P = list(map(int, input().split()))
Q = list(map(int, input().split()))

ans = [(Q[i], Q[P[i]-1]) for i in range(N)]
ans.sort()
print(*[x[1] for x in ans])