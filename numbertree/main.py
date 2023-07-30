s = input().split()
if len(s) == 1:
    h = s[0]
    p = ""
else:
    h,p = s
h = int(h)
ptr = 1

for c in p:
    ptr *= 2
    if c == 'R':
        ptr += 1
print((1<<(h+1))-ptr)
