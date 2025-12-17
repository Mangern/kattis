n=int(input())
a=list(map(int,input().split()))
s=list(map(int,input().split()))
s.sort()

sm=0
ans=0.0
for i in range(n):
    sm += s[n-i-1]
    ssolve=sm + a[i]
    ans=max(ans,ssolve/(i+1))
print(ans)
