import sys
imput = lambda : sys.stdin.readline().strip()

n = int(input())
strings = [None]*n
freqs = [None]*n
for i in range(n):
    strings[i] = sorted(input())

strings.sort()


count = 0
i = 0
while i < n:
    j = i
    while j < n and strings[j] == strings[i]:
        j += 1
    
    m = j-i
    count += m*(m-1)//2
    i = j

print(count)