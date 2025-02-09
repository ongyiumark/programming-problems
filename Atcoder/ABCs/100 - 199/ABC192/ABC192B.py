s = input()
a = s[0::2]
b = s[1::2]

if all([ord('a') <= ord(x) <= ord('z') for x in a]) and all([ord('A') <= ord(x) <= ord('Z') for x in b]):
    print("Yes")
else:
    print("No")