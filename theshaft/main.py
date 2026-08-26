from math import sqrt
g,c,t=map(float,input().split())
t1 = (-1 + sqrt(1 + 2 * g / c * t)) / (g / c)
t2 = t - t1
print(c*t2)
