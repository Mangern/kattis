x,y=map(int,input().split())
ans=0
for k in range(32,-1,-2):
    n3=k
    n2=(100-k*3)//2
    while n3 <= y and n2 <= x:
        ans += 1
        y -= n3
        x -= n2
print(ans)
