from math import sqrt
H, r, d_air, d_wat = map(float,input().split())

A = d_wat - d_air
B = 2 * d_air * H
C = -H*H*d_air

x = (-B+sqrt(B*B-4*A*C))/(2*A)

print(f"{x:.10f}")
