n,m,k=map(int,input().split())
a=sorted(map(int,input().split()))
ans=sum(a[-(m+k):])/sum(a)
print(ans*100)
