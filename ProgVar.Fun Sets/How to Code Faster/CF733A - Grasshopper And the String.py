s = input()
vowels = "AEIOUY"

prev_i = -1
curr_i = -1
ans = 0
for i, ch in enumerate("A"+s+"A"):
    if ch in vowels:
        prev_i = curr_i
        curr_i = i
        ans = max(ans, curr_i-prev_i)
print(ans)