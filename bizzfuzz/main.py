from math import lcm
a,b,c,d=map(int, input().split())
l = lcm(c,d)
print(b//l - (a-1)//l)
