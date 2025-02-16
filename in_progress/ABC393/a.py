s1, s2 = input().split()

ans = [("sick", "sick"), ("sick", "fine"), ("fine", "sick"), ("fine", "fine")]
print(ans.index((s1,s2))+1)