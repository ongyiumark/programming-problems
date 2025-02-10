def solve(ar):
    n = len(ar)
    for i in range(1, n):
        if ar[i-1]*ar[1]%ar[0] != 0 or ar[i] != ar[i-1]*ar[1]//ar[0]:
            return "No"
    
    return "Yes"


N = int(input())
A = list(map(int, input().split()))

print(solve(A))

