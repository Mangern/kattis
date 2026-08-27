from math import sqrt
n = int(input())
pts = [tuple(map(float, input().split())) for _ in range(n)]
xs,ys = zip(*pts)
A = float(input())

area = abs(sum(xs[i]*ys[(i+1)%n]-ys[i] * xs[(i+1)%n] for i in range(n))/2)
area_scale = area / A
length_scale = sqrt(area_scale)

xs = [x / length_scale for x in xs]
ys = [y / length_scale for y in ys]

minx = min(xs)
miny = min(ys)

xs = [x - minx for x in xs]
ys = [y - miny for y in ys]

print("\n".join(f"{x} {y}" for x,y in zip(xs,ys)))
