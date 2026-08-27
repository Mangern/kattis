h,n=map(int,input().split())
a,b,c,d=map(int,input().split())
damg={"standard":a,"fire":b,"ice":c,"light":d}
for _ in range(n):
    h -= damg[input()]
print("dead" if h <= 0 else h)
