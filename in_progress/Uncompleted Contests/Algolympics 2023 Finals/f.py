n = 12

total = 0
for a in range(1,n//3+1): 
    total += (n-a)//2 - a + 1

print(total)
