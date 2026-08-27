from math import inf


A,B,C,D=map(float,input().split())

def f(x):
    return x * x + A * x + B

def g(x):
    return x * x + C * x + D

x = inf

if f(-A/2) >= g(-A/2):
    x = min(x, -A/2)

if g(-C/2) >= f(-C/2):
    x = min(x, -C/2)

if A != C:
    x = min(x, (D-B)/(A-C))

print(x, max(f(x), g(x)))
