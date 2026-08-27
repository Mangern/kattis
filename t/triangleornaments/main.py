from math import sqrt

def get_sin(a,b,c):
    cos = (a*a+c*c-b*b)/(2*a*c)
    sinx = sqrt(1-cos*cos)
    l2 = (2*a*a+2*b*b-c*c)/4
    return c * sinx / (2*sqrt(l2))

n = int(input())
ans = 0
for i in range(n):
    a,b,c=map(int,input().split())

    ans += a * get_sin(a,b,c) + b * get_sin(b,a,c)

print(ans)
