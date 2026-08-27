s=input()
p,m=map(int,input().split())
r=s.replace
b=eval(r("x","0"))
a=eval(r("x","1"))-b
print(next(x for x in range(m)if not(a*x+b-p)%m))
