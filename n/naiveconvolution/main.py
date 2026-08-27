n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))

ans=[0]*(n+m)
for i in range(n):
    for j in range(m):
        ans[i+j] += a[i] * b[j]
while len(ans)>1 and ans[-1] == 0:
    ans.pop()
print(" ".join(map(str,ans)))
