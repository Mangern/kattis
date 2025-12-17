t,h=map(int,input().split())

if h / (2 * t) >= 1:
    print((2 * h * t)**0.5)
else:
    print(t + h / 2)
