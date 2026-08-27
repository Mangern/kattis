xp,yp=map(int,input().split())
xv,yv=map(int,input().split())
u=int(input())
d=(xp-xv)**2+(yp-yv)**2
if d > u:
    print("against")
elif d == u:
    print("on the fence")
else:
    print("for")
