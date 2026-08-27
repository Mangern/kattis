n,k=map(int,input().split())
a=list(map(int,input().split()))
ans=0
for i in range(n):
    ans=max(ans,sum(a[i:i+k]))
print(ans)
