n=int(input())

ph = 0
pa = 0
pt = 0
t_a = 0
t_h = 0
for _ in range(n):
    team, pts, t = input().split()
    pts = int(pts)
    m, s = t.split(":")
    t = int(m)*60 + int(s)

    if ph > pa:
        t_h += t - pt
    elif pa > ph:
        t_a += t - pt

    if team == "H":
        ph += pts
    else:
        pa += pts

    pt = t

if ph > pa:
    t_h += 32*60 - pt
elif pa > ph:
    t_a += 32*60 - pt

win = "A" if pa > ph else "H"

m_h = t_h // 60
s_h = t_h % 60
m_a = t_a // 60
s_a = t_a % 60

print(f"{win} {m_h}:{s_h:02d} {m_a}:{s_a:02d}")
