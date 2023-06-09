names = ["Sheldon", "Leonard", "Penny", "Rajesh", "Howard"]

n = int(input())-1
curr = 1
while n-curr*5 >= 0:
    n -= curr*5
    curr *= 2

print(names[n//curr])