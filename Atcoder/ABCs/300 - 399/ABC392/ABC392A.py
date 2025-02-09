a,b,c = list(map(int, input().split()))
print("Yes") if a*b == c or b*c == a or a*c == b else print("No")