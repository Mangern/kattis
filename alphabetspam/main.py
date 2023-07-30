s = input()

n = len(s)
whi = 0
low = 0
upp = 0
sym = 0

for c in s:
    if c == "_":
        whi += 1
    elif ord('a') <= ord(c) <= ord('z'):
        low += 1
    elif ord('A') <= ord(c) <= ord('Z'):
        upp += 1
    else:
        sym += 1

print(whi/n)
print(low/n)
print(upp/n)
print(sym/n)
