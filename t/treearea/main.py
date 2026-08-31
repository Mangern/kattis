n=int(input())
tris=[tuple(map(int,input().split())) for _ in range(n)]

ans=tris[-1][1]*tris[-1][2]
for i in range(n-1):
    b,r,h=tris[i]
    nb,nr,nh=tris[i+1]
    h_inter=b+h-nb
    r_inter=r*h_inter/h
    ans+=h*r-r_inter*h_inter
print(ans)
