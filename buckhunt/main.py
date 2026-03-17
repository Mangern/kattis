x1,x2,y1,y2=map(int,input().split())
if x2<x1:
    x1,x2=x2,x1
if y2<y1:
    y1,y2=y2,y1
ans=0
for _ in range(int(input())):
    x,y=map(int,input().split())
    if x1 <= x <= x2 and y1 <= y <= y2:
        ans += 1
print(ans)
