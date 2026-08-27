ans = [0]*51
c,n,m=map(int,input().split())
cnt =[0]*(c+1)
for _ in range(n):
    ci = int(input())
    cnt[ci] += 1

for d in range(51):
    ans[d] = sum(cnt)
    ncnt = [0]*(c+1)
    for ci in range(c+1):
        nmnt = ci * 2
        if nmnt <= c:
            ncnt[nmnt] += cnt[ci]
        else:
            n1 = nmnt // 2
            n2 = nmnt - n1
            ncnt[n1] += cnt[ci]
            ncnt[n2] += cnt[ci]
    cnt = ncnt

for _ in range(m):
    d = int(input())
    print(ans[d])
