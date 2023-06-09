a, b = [int(x) for x in input().split()]

n = max(a, b)
for i in range(n+1):    
    a_given = i*i
    b_given = i*(i+1)
    # print(i, a_given, b_given)
    if a_given <= a and b_given <= b:
        continue

    # print(i, a_given, b_given)
    if a_given > a and b_given > b:
        print("Vladik")
    elif a_given > a and b_given <= b:
        print("Vladik")
    elif a_given <= a and b_given > b:
        print("Valera")
    break