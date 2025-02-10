A = list(map(int, input().split()))

def is_sorted(ar):
    for x, y in zip(ar, sorted(ar)):
        if x != y:
            return False
    return True

n = len(A)
possible = False
for i in range(1,n):
    j = i-1
    A[i], A[j] = A[j], A[i]
    if is_sorted(A):
        possible = True
    A[i], A[j] = A[j], A[i]

print("Yes" if possible else "No")