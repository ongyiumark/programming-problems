n = int(input())
a = [int(x) for x in input().split()]
stack = []
for x in a:
    if len(stack) > 0 and stack[-1]%2 == x%2:
        stack.pop()
        continue
    stack.append(x)
print(len(stack))