from math import atan, tan
d,x,y,h = map(float,input().split())

a1 = atan((y-h/2)/x)
a2 = atan((y+h/2)/x)

a = atan(y/x)

ans = tan(a-a1)*d+tan(a2-a)*d

print(ans)

