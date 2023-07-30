a,b=map(float,input().split())
c,d=map(float,input().split())


if d == 0:
    x=1/c
    y=0
else:
    y=-1/(c*c/d+d)
    x=-c*y/d

ansa = a*x-b*y
ansb = b*x+a*y

print(ansa,ansb)
