from math import gcd
n=int(input())
input()
d=int(input())
if d < 0:
    n *= -1
    d *= -1
g=gcd(n,d)
n//=g
d//=g
if d == 1:
    print(n)
else:
    print(f"{n}/{d}")
