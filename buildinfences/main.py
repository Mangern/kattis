n=int(input())
mnx = 10**10
mxx = -mnx
mxy = mxx
mny = mnx

for _ in range(n):
    x,y=map(int,input().split())
    mxx=max(mxx,x)
    mnx=min(mnx,x)
    mxy=max(mxy,y)
    mny=min(mny,y)
print(2*(mxx-mnx+mxy-mny+4))
