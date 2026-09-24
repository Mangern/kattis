s=list(input())
t=[]
for c in s:
    if not t or t[-1] != c:
        t.append(c)

if len(t) % 2 == 1:
    t = t[:3]
else:
    t = t[:2]
print("".join(t))
