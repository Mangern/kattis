from math import sqrt, pi,tan
for _ in range(int(input())):
    n,l,d,g=map(int,input().split())
    p = l * n
    a = l / (2*tan(pi/n))
    A = (a * p / 2)

    ans = pi * d * g * d * g + A + n * d * g * l
    print(ans)
