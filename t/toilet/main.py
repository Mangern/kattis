s = input()
x, s = s[0], s[1:]

a,b,c = 0,0,0

n = len(s)

cra, crb, crc = x,x,x

for i,ch in enumerate(s):
    if cra != ch:
        a += 1
    if crb != ch:
        b += 1
    if crc != ch:
        c += 1
        crc = ch

    cra = 'U'
    if ch != 'U':
        a += 1
    crb = 'D'
    if ch != 'D':
        b += 1

print(a)
print(b)
print(c)
