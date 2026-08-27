from math import*
r=9**6
A,*l=([*map(float,x.split())]for x in open(0))
print(l.index(min(l,key=lambda x:abs(A[0]-(lambda c,d,e:pi*e/r*sum((d*(y:=e*(i+.5)/r)**.5+c*exp(-y*y))**2for i in range(r)))(*x)))))
