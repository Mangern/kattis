from math import radians, sin, floor
h,v=map(int,input().split())

if 0 <= v <= 180:
    print("safe")
    exit()

ang=v-180
print(int(floor(h/sin(radians(ang)))))
