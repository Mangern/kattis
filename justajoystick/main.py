n=int(input())
s=input()
t=input()
ans=0
for a,b in zip(s,t):
    dist=abs(ord(a)-ord(b))
    dist=min(dist,26-dist)
    ans+=dist
print(ans)
