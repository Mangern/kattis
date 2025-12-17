from math import gcd
a,b=map(int,input().split("/"))
a *= 5
b *= 9
a,b=9*a-5*32*b,9*b

g = gcd(a,b)
a //= g
b //= g
print(f"{a}/{b}")
