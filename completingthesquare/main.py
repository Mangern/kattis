def dot(u,v):
    return u[0]*v[0]+u[1]*v[1]

def trans_from(a,b,c):
    return ((b[0]-a[0],b[1]-a[1]),(c[0]-a[0],c[1]-a[1]))

pos = [tuple(map(int,input().split())) for i in range(3)]

for k in range(3):
    t = trans_from(*pos)
    if dot(*t) == 0:
        x = pos[0][0]+sum(z[0] for z in t)
        y = pos[0][1]+sum(z[1] for z in t)
        print(x,y)
    pos = [pos[1],pos[2],pos[0]]
