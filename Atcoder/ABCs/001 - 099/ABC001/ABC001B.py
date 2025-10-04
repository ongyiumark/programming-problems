m = int(input())

if m < 100: print("00")
if 100 <= m <= 5_000: print(f"{m//100:02}")
if 6_000 <= m <= 30_000: print(m//1000+50)
if 35_000 <= m <= 70_000: print((m//1000-30)//5 + 80)
if 70_000 < m: print("89")