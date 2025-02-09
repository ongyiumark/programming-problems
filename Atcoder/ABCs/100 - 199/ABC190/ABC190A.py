a, b, c = [int(x) for x in input().split()]

if c == 0:
    if a <= b:
        print("Aoki")
    else:
        print("Takahashi")
else:
    if a < b:
        print("Aoki")
    else:
        print("Takahashi")