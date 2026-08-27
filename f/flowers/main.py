from math import*
R,I,F=range,input,float
s=I()
t=m=1e9
for i in R(int(s[-1])):a,b,h=map(F,I().split());u=h/1e6;m,t=min((m,t),(abs(F(s[:-1])-pi*u*sum((a*exp(-(x:=u/2+i*u)*x)+b*x**.5)**2for i in R(10**6))),i))
print(t)
