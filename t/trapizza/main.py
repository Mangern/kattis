from math import pi
d,a,b,h=[int(input()) for _ in range(4)]
a1 = pi * (d/2)**2
a2 = h * (a + b) / 2
print("Mahjong!" if a1 > a2 else "Trapizza!" if a2 > a1 else "Jafn storar!")
