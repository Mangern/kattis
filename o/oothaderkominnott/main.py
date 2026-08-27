w,h,l=0,0,0
i=int(input())
if i == 1:
    w=l=int(input())
    h=3
elif i == 2:
    w=int(input())
    l=int(input())
    h=3
else:
    w=int(input())
    l=int(input())
    h=int(input())
ans=w*h*2+h*l*2+w*l-h*4+4-w*2-l*2
print(ans)
