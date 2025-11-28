n,x,m=map(int,input().split())
cr=0
cl=0
for i in range(m):
    r=int(input())
    if r < x:
        cr += 1
    else:
        cl += 1
print(min(cr,cl))
