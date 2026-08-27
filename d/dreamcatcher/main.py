from math import gcd
n=int(input())
i=(n+1)//2
while i>=1:
    if gcd(n,i) == 1:
        break
    i -= 1
print(i)
