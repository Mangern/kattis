from math import ceil
w=int(input())
m=int(input())
c=int(input())
J=w*m*60
c/=100
c/=1000
c/=3600
print(ceil(J*c))
