n = int(input())
cnt = 0

val = False
for _ in range(n):
    a, b = [int(x) for x in input().split()]
    if (a == b): 
        cnt += 1
    else:
        cnt = 0
    
    if (cnt >= 3):
        val = True

print("Yes" if val else "No") 

