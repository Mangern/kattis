need=list(map(int,input().split()))
have=list(map(int,input().split()))
for i in range(3):
    need[i] = max(0, need[i] - have[i])
c01,c12=map(int,input().split())
ans=0

buy0=min(c01,need[0])
ans+=buy0
need[0] -= buy0
c01 -= buy0

buy1=min(c12,need[2])
ans+=buy1
need[2] -= buy1
c12 -= buy1

buy01=min(c01+c12,need[1])
ans+=buy01
need[1] -= buy01
if max(need) == 0:
    print(ans)
else:
    print(-1)
