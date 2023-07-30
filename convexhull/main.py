from math import acos
from functools import cmp_to_key
import sys

def dist(a,b):
    return ((a[0]-b[0])**2+(a[1]-b[1])**2)

def mandist(a,b):
    return abs(a[0]-b[0])+abs(a[1]-b[1])

def angle(u,v):
    cosof = (u[0] * v[0] + u[1] * v[1])/(dist((0,0),u)*dist((0,0),v))
    return round(-cosof,4)


def vecto(fr,to):
    return (to[0]-fr[0],to[1]-fr[1])

def ccw(a,b,c):
    val = (c[1]-a[1]) * (b[0]-a[0]) - (b[1]-a[1]) * (c[0]-a[0])
    return 0 if val == 0 else (2 if val > 0 else 1) 


p0 = (-1,-1)
def anglecmp(p1,p2):
    o = ccw(p0,p1,p2)
    if o == 0:
        return -1 if dist(p0,p2) >= dist(p0,p1) else 1
    return -1 if o == 2 else 1 


while True:
    n = int(input())
    if not n:
        break

    tps = []
    for i in range(n):
        x,y = map(int,input().split())
        tps.append((x,y))

    tps.sort(key=lambda p: (p[1],p[0]))


    p0 = tps[0]
    tps = tps[:1] + list(sorted(tps[1:], key=cmp_to_key(anglecmp))) 

    ps = [tps[0]]
    
    for i in range(1,len(tps)):
        while i < len(tps) and tps[i] == ps[-1]:
            i += 1
        if i >= len(tps):
            break
        while i < len(tps)-1 and ccw(p0,tps[i],tps[i+1]) == 0:
            i += 1
        if i >= len(tps):
            break
        ps.append(tps[i])

    if len(ps) >= 3:
        hull = [ps[0]]

        for i in range(1,len(ps)):
            #print(hull)


            while len(hull) >= 2 and ccw(hull[-2], hull[-1], ps[i]) != 2:
                hull.pop()

            hull.append(ps[i])


        if len(hull) >= 2 and hull[-1] == hull[0]:
            hull.pop()
    else:
        hull = ps
    print(len(hull))
    for x,y in hull:
        print(f"{x} {y}")

