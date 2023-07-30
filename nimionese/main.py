def near(c, lst):
    mn = lst[0]
    for s in lst:
        if abs(ord(c) - ord(s[0])) < abs(ord(c)-ord(mn[0])):
            mn = s
        elif abs(ord(c)-ord(s[0])) == abs(ord(c)-ord(mn[0])) and s[0] < mn[0]:
            mn = s
    return mn

s = input().split()

HARD = ['b','c','d','g','k','n','p','t']
for w in s:
    syl = w.split("-")
    x = syl[0]
    n = near(x[0].lower(), HARD)
    if x[0].lower() != x[0]:
        n = n.upper()
    x = n + x[1:]
    for y in syl[1:]:
        res = y
        for c in HARD:
            res = res.replace(c,x[0].lower())
        x += res
    if x[-1].lower() in HARD:
        x += near(x[-1].lower(), ['ah','oh','uh'])
    print(x, end=" ")
print()
