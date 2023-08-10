from math import sqrt,floor

cx,cy,n=map(int,input().split())

pos = [tuple(map(int,input().split())) for i in range(n)]

dists = []
for x,y,r in pos:
    if (x-cx)*(x-cx)+(y-cy)*(y-cy) <= r * r:
        dists.append(0)
    else:
        dists.append(sqrt((x-cx)*(x-cx)+(y-cy)*(y-cy)) - r)

dists.sort()


print(floor(dists[2]))
