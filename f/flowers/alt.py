from math import*
R,I,F=range,input,float,;v,n=I().split();t=m=1e9
def j(x):
    return 0.5928943197681*(x - log(0.6154047668869*exp(3.5383445957136*x)+1)/3.5383445957136)
def f(a,b,h):
    p1 = a*a*0.5*sqrt(pi/2)*erf(sqrt(2)*h)
    p2 = 2*a*b*(0.4533919444517 +j(h-1))
    p3 = b*b*h*h/2
    return p1+p2+p3
for i in R(int(n)):
    a,b,h=map(F,I().split());
    m,t=min((m,t),(abs(F(v)-pi*f(a,b,h)-1),i))
print(t)
