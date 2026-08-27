from fractions import Fraction

def nck(n,k):
    num=1
    den=1

    for i in range(k):
        num *= n - i
        den *= i + 1

    return Fraction(num, den)

n=int(input())
ts=list(map(int,input().split()))
s=sum(ts)

num = Fraction(1,1)

for i in range(1, n+1):
    num *= i

den=Fraction(1,1)
for t in ts:
    den *= nck(s, t)
    s -= t 

num /= den
print(f"{num.numerator}/{num.denominator}")
