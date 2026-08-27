from math import pi
while True:
    D,V=map(float,input().split())

    if not D+V:
        break

    d = V
    d -= pi * (D/2)*(D/2)*D
    d += (2/3)*pi*D*D*D/8
    d /= pi
    d /= (1/12-1/4)
    d = d**(1./3.)
    print(d)
