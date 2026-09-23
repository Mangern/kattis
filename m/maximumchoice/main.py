n,b=map(int,input().split())
ans=0
k=1
while n>0:
    n = n // (b + 1)
    ans += 1
print(ans)
