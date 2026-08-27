from math import sqrt

def dist(x1,y1,x2,y2):
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))

while True:
    d,n=input().split()
    d = float(d)
    n = int(n)
    if n+d==0:
        break
    pos = [tuple(map(float,input().split())) for _ in range(n)]
    sour = 0
    sweet = 0
    for i,(x,y) in enumerate(pos):
        has_sour = False
        for x1,y1 in [pos[j] for j in range(n) if j != i]:
            if dist(x,y,x1,y1) <= d:
                has_sour = True
                break
        if has_sour:
            sour += 1
        else:
            sweet += 1
    print(f"{sour} sour, {sweet} sweet")
