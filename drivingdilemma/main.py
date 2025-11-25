s=int(input())
d=float(input())
t=float(input())

fps = s * 5280 / 3600

if t*s*5280 >= d*3600:
    print("MADE IT")
else:
    print("FAILED TEST")
