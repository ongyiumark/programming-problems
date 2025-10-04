s = input()
pattern = "WBWBWWBWBWBW"
keys = [0, 2, 4, 5, 7, 9, 11]
ans = ["Do", "Re", "Mi", "Fa", "So", "La", "Si"]

result = None
for idx, i in enumerate(keys):
    t = []
    for j in range(20):
        t.append(pattern[(i+j)%len(pattern)])

    if s == ''.join(t):
        result = ans[idx]
print(result)