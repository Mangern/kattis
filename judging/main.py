n=int(input())
cnt1={}
cnt2={}
for _ in range(n):
    res=input()
    cnt1[res]=cnt1.get(res,0)+1
for _ in range(n):
    res=input()
    cnt2[res]=cnt2.get(res,0)+1

ans=0
for k in cnt1:
    if k in cnt2:
        ans+=min(cnt1[k],cnt2[k])
print(ans)
