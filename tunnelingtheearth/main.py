from math import cos, sin, pi,hypot, acos
R=6371009
for _ in range(int(input())):
    lat1, long1, lat2, long2 = map(lambda x: float(x) * pi / 180, input().split())
    x1,y1,z1 = R*cos(lat1)*sin(long1), R*cos(lat1)*cos(long1), R*sin(lat1)
    x2,y2,z2 = R*cos(lat2)*sin(long2), R*cos(lat2)*cos(long2), R*sin(lat2)
    alpha=acos((x1*x2+y1*y2+z1*z2)/R**2)
    alpha=abs(alpha)
    dstraight=hypot(x1-x2,y1-y2,z1-z2)
    daround=alpha * R
    print(daround - dstraight)
