from math import asin,atan,sqrt,pi

def get_angle(x,y):
    if x == 0:
        return pi/2 if y > 0 else pi+pi/2
    if y > 0:
        return atan(y/x) if x > 0 else pi-atan(-y/x)
    else:
        return pi+atan(y/x) if x < 0 else 2*pi-atan(-y/x)

def get_cnt(angs):
    mend = -1.0
    cnt = 0
    angs.sort(key = lambda t: t[1])
    for l,r in angs:
        if l > mend:
            cnt += 1
            mend = r
    return cnt


for _ in range(int(input())):
    n,d=map(int,input().split())
    pos = [tuple(map(int,input().split())) for i in range(n)]
    pos = [(x,y) for x,y in pos if x*x+y*y>d*d]
    ang1 = []
    ang2 = []
    for x,y in pos:
        angle_here = get_angle(x,y) 
        angle_min = angle_here - asin(d / sqrt(x*x+y*y))
        angle_max = angle_here + asin(d / sqrt(x*x+y*y))
        if angle_max >= 2*pi:
            ang1.append((angle_min,2*pi))
            ang2.append((0, angle_max-2*pi))
        else:
            ang1.append((angle_min,angle_max))
            ang2.append((angle_min,angle_max))
    print(min(get_cnt(ang1),get_cnt(ang2)))

