input()
a=[0]+list(map(int,input().split()))
ans=0
for x,y in zip(a,a[1:]):
    ans+=abs(x-y)
print(ans)
