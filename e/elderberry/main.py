
from fractions import Fraction
a,b,c=map(Fraction,input().split())
eps=1e-10
ans_a=Fraction(0)
ans_b=Fraction(0)
ans_c=Fraction(0)

while max(a,b,c)>0:
    x=float('inf')
    if a>0:
        x = min(x, 16*a/3)
    if b>0:
        x = min(x, 16*b/3)
    if c>0:
        x = min(x, 16*c/10)

    ans_a += max(0, 3*x/16 - a)
    ans_b += max(0, 3*x/16 - b)
    ans_c += max(0, 10*x/16 - c)
    a -= 3 * x / 16
    b -= 3 * x / 16
    c -= 10 * x / 16
    a = max(0, a)
    b = max(0, b)
    c = max(0, c)
print(float(ans_a), float(ans_b), float(ans_c))
