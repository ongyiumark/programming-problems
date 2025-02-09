d = input()
opposite = {key: val for key, val in zip("NSEW","SNWE")}
result = map(lambda ch: opposite[ch], d)
print(''.join(result))