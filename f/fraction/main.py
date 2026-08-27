from math import floor
from fractions import Fraction

def to_frac(lst):
    f = Fraction(lst[-1], 1)
    for x in lst[::-1][1:]:
        f = x + 1/f
    return f

def to_cont(frac: Fraction):
    ans = []
    while frac != 0:
        x = floor(frac)
        ans.append(x)
        frac -= x
        if frac == 0:
            break
        frac = 1 / frac
    return ans


n1, n2 = map(int, input().split())

a1 = list(map(int, input().split()))
a2 = list(map(int, input().split()))

r1 = to_frac(a1)
r2 = to_frac(a2)

ans1 = r1 + r2
ans2 = r1 - r2
ans3 = r1 * r2
ans4 = r1 / r2

print("\n".join(" ".join(map(str, to_cont(a))) for a in [ans1,ans2,ans3,ans4]))
