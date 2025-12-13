from math import asin, pi
n,m=map(int,input().split())
a = [list(map(int, input().split())) for _ in range(n)]

d = 360 / m
ans=0.0
for j in range(m):
    for i in range(n):
        phi = pi / n
        ans += (d / 360) * phi / pi * a[i][j] / 100

print(ans*100)
