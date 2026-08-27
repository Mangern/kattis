x,y=map(int,input().split())
area = 31250

sw = False
ans = (0,0)
if min(x,y) == 0:
    if x == 0:
        x,y=y,x
        sw = True
    if x <= 125:
        h = area/(250-x)
        ans = (250-h,h)
    else:
        h = area/x
        ans = (0,h)

else:
    if y < 125:
        x,y=y,x
        sw = True
    w = area/y
    ans = (250-w,0)


if sw:
    ans = (ans[1],ans[0])

print(f"{ans[0]:.2f} {ans[1]:.2f}")
