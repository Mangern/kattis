from math import pi, atan, asin, sqrt
n = int(input())

circs = []
for i in range(n):
    x,y,r = map(float,input().split())
    circs.append((x,y,r))

def normi(angle):
    while angle >= 2*pi:
        angle -= 2*pi
    while angle < 0:
        angle += 2*pi
    return angle

def transfi(a,b):
    if b < a:
        return [(a,2*pi),(0,b)]
    return [(a,b)]

block = []
for i in range(n):
    for j in range(i+1,n):
        x1,y1,r1 = circs[i]
        x2,y2,r2 = circs[j]

        if abs(x1-x2) <= 0.00000001:
            theta = pi / 2
        else:
            theta = atan((y2-y1)/(x2-x1))

        theta = normi(theta)

        d = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
        d2 = d / (1 + r1/r2)
        alpha = asin(r2 / d2)

        block += transfi(normi(theta-alpha),normi(theta+alpha))
        theta = normi(theta+pi)
        block += transfi(normi(theta-alpha),normi(theta+alpha))

block.sort()
 

block = block

prv = block[0][1]
ans = 0
for i in range(len(block)):
    if block[i][0] > prv:
        ans = max(ans,block[i][0] - prv)

    prv = max(prv,block[i][1])

if prv == 2*pi:
    ans = max(ans,block[0][0])

if abs(ans) < 0.00000001:
    print(0)
else:
    print(ans)
