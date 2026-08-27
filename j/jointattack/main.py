from math import gcd
n=int(input())
a=list(map(int,input().split()))
num=1
den=0
for x in a[::-1]:
    num,den=den,num
    num,den=x*den+num,den
    g = gcd(num,den)
    num //= g
    den //= g
print(f"{num}/{den}")
