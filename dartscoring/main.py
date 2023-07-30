from math import acos
import sys

def dist(a,b):
    return ((a[0]-b[0])**2+(a[1]-b[1])**2)**0.5

def angle(u,v):
    return acos((u[0] * v[0] + u[1] * v[1])/(dist((0,0),u)*dist((0,0),v)))

def vecto(fr,to):
    return (to[0]-fr[0],to[1]-fr[1])

def ccw(a,b,c):
    val = (c[1]-a[1]) * (b[0]-a[0]) - (b[1]-a[1]) * (c[0]-a[0])
    return val >= 0

for line in sys.stdin.readlines():
    in_lst = list(map(float,line.split()))
    ps = list(zip(in_lst[::2],in_lst[1::2]))
    ps.sort()

    ps = ps[:1] + list(sorted(ps[1:], key= lambda p: angle((0,-1),vecto(ps[0],p))))

    hull = [ps[0]]

    for i in range(1,len(ps)):
        #print(hull)
        hull.append(ps[i])

        while len(hull) >= 3 and ccw(hull[-3],hull[-1],hull[-2]):
            save = hull.pop()
            hull.pop()
            hull.append(save)

    #print(hull)

    lst = hull[0]
    ans = dist(hull[0],hull[-1])
    for p in hull:
        ans += dist(lst,p)
        lst = p

    ans = 100 * len(ps) / (1 + ans)
    print(ans)

