h1, m1, s1 = map(int, input().split(":"))
h2, m2, s2 = map(int, input().split(":"))

t1 = (h1 * 3600 + m1 * 60 + s1) % (24 * 3600)
t2 = (h2 * 3600 + m2 * 60 + s2) % (24 * 3600)

dt = (t2 - t1) % (24 * 3600)

ha = dt // 3600
ma = (dt - ha * 3600) // 60
sa = dt - ha * 3600 - ma * 60

if ha == 0 and ma == 0 and sa == 0:
    ha = 24

print(f"{ha:02d}:{ma:02d}:{sa:02d}")
