s = input()
n = len(s)

total = 0
for i in range(n):
    for j in range(i+1, n):
        k = j + (j-i)
        if k >= n:
            continue
        
        total += ((s[i], s[j], s[k]) == ("A", "B", "C"))

print(total)