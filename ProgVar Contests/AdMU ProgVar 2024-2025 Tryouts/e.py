n = int(input())
difficulties = [int(input()) for _ in range(n)]

no_val = True
for k in range(2, n+1):
    if n % k != 0:
        continue
    
    m = n//k
    valid = True
    for i in range(k-1):
        curr_section = difficulties[i*m : (i+1)*m]
        next_section = difficulties[(i+1)*m : (i+2)*m]
        valid &= (max(curr_section) < min(next_section))

    if valid:
        no_val = False
        print(k)

if no_val:
    print(-1)