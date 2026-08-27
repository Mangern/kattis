n = int(input())
d = float(input())

win = None
best = 0

for _ in range(n):
    name, v, r = input().split()
    v = float(v)
    r = float(r)
    t = d / v
    rat = r / t
    if v / rat > best:
        best = v / rat
        win = name

print(win)
