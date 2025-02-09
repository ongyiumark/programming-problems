N, M = list(map(int, input().split()))
A = set(map(int, input().split()))

X = list()
for i in range(1, N+1):
    if i not in A:
        X.append(i)

X.sort()
print(len(X))
print(*X)