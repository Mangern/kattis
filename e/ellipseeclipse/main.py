from math import atan2, sqrt, hypot, sin, cos, pi
x1,y1,x2,y2,d=map(int,input().split())

xm = (x1+x2)/2
ym = (y1+y2)/2
x1 -= xm
x2 -= xm
y1 -= ym
y2 -= ym
theta = atan2(y1-y2, x1-x2)
a=d/2
b=sqrt(d**2/4-hypot(x1,y1)**2)
alpha=a*cos(theta)
beta=-b*sin(theta)
gamma=a*sin(theta)
delta=b*cos(theta)

t1=atan2(beta, alpha)
t2=atan2(delta, gamma)
xs=[
    alpha*cos(t1)+beta*sin(t1)+xm,
    alpha*cos(t1+pi)+beta*sin(t1+pi)+xm
]
ys=[
    gamma*cos(t2)+delta*sin(t2)+ym,
    gamma*cos(t2+pi)+delta*sin(t2+pi)+ym
]
print(min(xs),min(ys),max(xs),max(ys))
