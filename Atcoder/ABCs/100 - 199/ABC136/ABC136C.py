n = int(input())
h = list(map(int, input().split()))

def solve():
    for i in range(n-2, -1, -1):
        if h[i] > h[i+1]:
            h[i] -= 1
            if h[i] > h[i+1]:
                return False
    
    return True

print("Yes" if solve() else "No")