from math import pi
ans = 0
for _ in range(int(input())):
    d, r1, r2 = map(int, input().split())
    ans += (d/360) * pi * (r2 * r2 - r1 * r1)
print(ans)
