n = int(input())
def compare(a, b):
    if a < b: return '<'
    elif a > b: return '>'
    else: return '='

for _ in range(n):
    a, b = [int(x) for x in input().split()]
    print(compare(a,b))