from math import cos, radians, sqrt
n, g = input().split()
n = int(n)
g = float(g)

vels = []

for _ in range(n):
    d, theta = map(float, input().split())
    vels.append(0)

    a = g * cos(radians(theta))

    for i in range(len(vels)):
        v0 = vels[i]
        t = (sqrt(v0*v0 + 2 * a * d) - v0) / a
        vels[i] += a * t
for v in vels:
    print(v)
