from math import sin, cos, hypot
f,g,t=map(int,input().split())
r=6378137

p1 = (r, f * t)
omega = g / r

p2 = (r * cos(omega * t), r * sin(omega * t))
print(hypot(p1[0] - p2[0], p1[1] - p2[1]))
