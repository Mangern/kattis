sm = 0
s = input()
for c in s:
    sm += ord(c)

sm //= len(s)
print(chr(sm))
