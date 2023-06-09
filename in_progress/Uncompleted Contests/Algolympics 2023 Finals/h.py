import math
def herons(a, b, c):
    s = (a+b+c)/2
    return (s*(s-a)*(s-b)*(s-c))**0.5

a, b, c = [float(x) for x in input().split()]
print(herons(a,b,c))