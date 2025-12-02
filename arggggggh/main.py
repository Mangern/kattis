n=int(input())
x,y=map(int,input().split())
for _ in range(n-1):
    w,d=input().split()
    d=int(d)
    dx=0
    dy=0
    if "N" in w:
        dy=1
    if "S" in w:
        dy=-1
    if "E" in w:
        dx=1
    if "W" in w:
        dx=-1
    scale=d/(dx*dx+dy*dy)**0.5
    dx *= scale
    dy *= scale
    x += dx
    y += dy
print(x,y)
