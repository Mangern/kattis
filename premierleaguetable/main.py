pts={}
gf={}
ga={}
mp={}
win={}
drw={}
los={}
for _ in range(int(input())):
    team1, score, team2 = input().split()
    g1, g2 = map(int, score.split("-"))
    pts[team1] = pts.get(team1, 0) + (3 if g1 > g2 else 1 if g1 == g2 else 0)
    pts[team2] = pts.get(team2, 0) + (3 if g2 > g1 else 1 if g1 == g2 else 0)
    gf[team1] = gf.get(team1, 0) + g1
    gf[team2] = gf.get(team2, 0) + g2
    ga[team1] = ga.get(team1, 0) + g2
    ga[team2] = ga.get(team2, 0) + g1
    mp[team1] = mp.get(team1, 0) + 1
    mp[team2] = mp.get(team2, 0) + 1
    win[team1] = win.get(team1, 0) + (1 if g1 > g2 else 0)
    win[team2] = win.get(team2, 0) + (1 if g2 > g1 else 0)
    drw[team1] = drw.get(team1, 0) + (1 if g1 == g2 else 0)
    drw[team2] = drw.get(team2, 0) + (1 if g1 == g2 else 0)
    los[team1] = los.get(team1, 0) + (1 if g1 < g2 else 0)
    los[team2] = los.get(team2, 0) + (1 if g2 < g1 else 0)

ans=[]
for t in pts:
    ans.append((-pts[t], ga[t]-gf[t], t.lower(), t))
ans.sort()

for _, _, _, t in ans:
    print(t, mp[t], win[t], drw[t], los[t], gf[t], ga[t], gf[t] - ga[t], pts[t])
