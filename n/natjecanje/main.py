n,s,r=map(int,input().split())
ars = map(int,input().split())
bs = map(int,input().split())

dmg = [False for i in range(n)]
for x in ars:
    dmg[x-1] = True

for b in sorted(bs):
    b -= 1
    for i in [b,b-1,b+1]:
        if 0 <= i < n and dmg[i]:
            dmg[i] = False
            break

print(sum(dmg))
