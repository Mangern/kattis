import math
def fac(n):
    ret=1
    for j in range(1,n+1):
        ret *= j
    return ret
def solve(n):
    n=min(100,n)
    p=fac(n)
    d=round(p/math.e)
    return 1.0-d/p
print(solve(int(input())))
