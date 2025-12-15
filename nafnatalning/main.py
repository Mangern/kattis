n,p=map(int,input().split())
a=list(map(int,input().split()))
s=sum(a)
top=0
for x in a:
    top += x * (s - x)
top //= 2
print((top+p-1)//p)
