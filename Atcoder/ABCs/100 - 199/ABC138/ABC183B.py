n = int(input())
a = list(map(int, input().split()))
total = 0
for x in a:
    total += 1/x
print(f"{1/total:.10f}")