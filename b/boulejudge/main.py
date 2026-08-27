xj,yj=map(int,input().split())
p1=[tuple(map(int,input().split())) for _ in range(6)]
p2=[tuple(map(int,input().split())) for _ in range(6)]
p1d=[(xi-xj)**2+(yi-yj)**2 for xi, yi in p1]
p2d=[(xi-xj)**2+(yi-yj)**2 for xi, yi in p2]
p1m=min(p1d)
p2m=min(p2d)

if p1m==p2m:
    print("TIE")
    exit()

if p1m<p2m:
    print("JONNA")
    print(sum(1 for x in p1d if x < p2m))
else:
    print("OPPONENTS")
    print(sum(1 for x in p2d if x < p1m))
