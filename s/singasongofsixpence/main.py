from math import floor
pi = 3.14159
R = float(input())
r = float(input())
h = float(input())
bird = float(input())
input()

v = pi * h * (R * R + R * r + r * r) / 3.0

ans = floor(v / bird)

print(f"{ans} birds")
