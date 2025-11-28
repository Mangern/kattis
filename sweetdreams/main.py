xb,yb=map(int,input().split())
md= 10**9
for _ in range(int(input())):
    x,y=map(int,input().split())
    md=min(md, (x-xb)*(x-xb)+(y-yb)*(y-yb))
print("NO" if md <= 64 else "YES")
