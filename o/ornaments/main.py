from math import acos,sqrt,pi
while True:
    r,h,s=map(int,input().split())

    if not r+h+s:
        break

    l = sqrt(h*h-r*r)
    a = acos(r/h)

    O = 2 * r * (pi-a) + 2 * l

    O *= (s/100+1)

    print(f"{O:.2f}")
