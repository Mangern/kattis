def area(a,b,c):
    return abs(a[0]*(b[1]-c[1])+b[0]*(c[1]-a[1])+c[0]*(a[1]-b[1]))/2

p,q,r=[list(map(int,input().split())) for i in range(3)]
print(area(p,q,r))

n = int(input())
cnt = 0
for i in range(n):
    x=list(map(int,input().split()))
    sm = area(p,q,x)+area(p,r,x)+area(q,r,x)
    if sm == area(p,q,r):
        cnt += 1
print(cnt)
