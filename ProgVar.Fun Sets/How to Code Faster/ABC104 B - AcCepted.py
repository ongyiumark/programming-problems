s = input()

n = len(s)
val = True
for i, ch in enumerate(s):
    if i == 0 and ch != 'A':
        val = False
    if ch not in "AC" and ch.lower() != ch:
        val = False
    
c_count = 0
for ch in s[2:-1]:
    c_count += (ch == 'C')

if c_count != 1:
    val = False

print("AC") if val else print("WA")