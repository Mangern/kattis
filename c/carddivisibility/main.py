l,r=map(int,input().split())
s=(r*(r+1))//2 - l*(l-1)//2
print(s%9)
