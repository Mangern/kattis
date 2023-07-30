from math import log, pow,sqrt
n,p,s,v=map(float,input().split())

def check(c):
    return n * pow(log(n)/log(2), c*sqrt(2))/(p*pow(10,9)) + (s * (1+1/c))/v

ACC = 0.0000001
lo = 0.00001
hi = 100

while hi - lo > ACC:
    mid1 = (hi+lo)/2
    mid2 = mid1+ACC
    a = check(mid1)
    b = check(mid2)

    if a > b:
        lo = mid1
    else:
        hi = mid1

ans = (lo+hi)/2
print(check(ans), ans)
