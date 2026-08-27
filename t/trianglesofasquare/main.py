x1,y1,x2,y2=map(int,input().split())
corn={(0,0),(0,2024),(2024,0),(2024,2024)}
ans=2
if (x1,y1)in corn:
    ans -=1
if (x2,y2)in corn:
    ans -=1
print(ans)
