from math import tan,pi
d,h=map(int,input().split())
print("Yes" if h/d <= tan(15 * pi / 180) else "No")
