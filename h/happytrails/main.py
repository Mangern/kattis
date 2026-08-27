from math import sin,pi
h=0.0
for _ in range(int(input())):
    a,d=map(int,input().split())
    h += sin(a*pi/180)*d
print(f"{h:.2f}")
