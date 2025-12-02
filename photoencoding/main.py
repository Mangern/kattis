m=int(input())
avail={}
for r in range(0,201):
    for c in range(0,201):
        d=r+c
        if d not in avail:
            avail[d] = []
        avail[d].append((r,c))
for k in avail:
    avail[k].sort(key=lambda t: -max(t[0],t[1]))

ans=0
for _ in range(m):
    d=int(input())
    r,c=avail[d].pop()
    ans=max(ans,max(r,c)+1)
print(ans)
