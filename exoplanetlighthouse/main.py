from math import acos, sqrt

for _ in range(int(input())):
    R,h1,h2=map(float,input().split())
    R *= 1000
    Rh1 = R+h1
    Rh2 = R+h2
    x1 = sqrt(Rh1*Rh1-R*R)
    x2 = sqrt(Rh2*Rh2-R*R)
    a = acos((Rh1*Rh1+Rh2*Rh2-(x1+x2)*(x1+x2))/(2*Rh1*Rh2))
    D = a * R
    D /= 1000
    print(D)


