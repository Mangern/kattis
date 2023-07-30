n,m=map(int,input().split())
a = [list(map(int,input().split())) for i in range(n)]

def getmn(mi,mj):
    ret = 0
    for i in range(n):
        for j in range(m):
            ret += a[i][j] * (abs(i - mi) + abs(j - mj))
    return ret

ans = getmn(0,0)
for i in range(n):
    for j in range(m):
        ans = min(ans,getmn(i,j))
print(ans)

