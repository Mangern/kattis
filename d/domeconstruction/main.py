from math import hypot
n,k=map(int,input().split())
dists=[]
for _ in range(n):
    x,y,z=map(float,input().split())
    dists.append(hypot(x,y,z))
dists.sort()
print(dists[k-1])
