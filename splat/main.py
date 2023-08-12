from math import sqrt, pi
for _ in range(int(input())):
    n = int(input())
    circs = [input().split() for i in range(n)]
    for c in circs:
        c[0], c[1], c[2] = map(float,c[:-1])
        c[2] = sqrt(c[2]/pi)

    q = int(input())
    for k in range(q):
        x,y=map(float,input().split())
        ans = "white"
        for cx,cy,r,col in circs:
            if (x-cx)*(x-cx)+(y-cy)*(y-cy) <= r*r:
                ans = col
        print(ans)

