ans1=0
ans2=0
for _ in range(10):
    p1 = list(map(int,input().split()[1:]))
    p2 = list(map(int,input().split()[1:]))
    pos1 = list(zip(p1[::2],p1[1::2]))
    pos2 = list(zip(p2[::2],p2[1::2]))
    dist1 = [(x-144)**2+(y-84)**2 for x, y in pos1]
    dist2 = [(x-144)**2+(y-84)**2 for x, y in pos2]
    if not dist1:
        ans2 += len(dist2)
        continue
    if not dist2:
        ans1 += len(dist1)
        continue
    m1 = min(dist1)
    m2 = min(dist2)

    if m1 < m2:
        ans1 += sum(1 for d in dist1 if d < m2)
    else:
        ans2 += sum(1 for d in dist2 if d < m1)
print(ans1, ans2)
