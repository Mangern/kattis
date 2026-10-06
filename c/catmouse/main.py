from math import pi, asin
for _ in range(int(input())):
    R,t,j=map(int,input().split())
    r=R*t/j
    if r>=R or (R**2-r**2)**0.5/t <= R*(1.5*pi-asin(r/R))/j:
        print("YES")
    else:
        print("NO")
