n,H=map(int,input().split())
ans=0
bk=[tuple(map(int,input().split())) for _ in range(n)]

for l,w,h in bk:
    l1,l2,l3=sorted((l,w,h))
    if l2 <= H:
        ans += l1
    elif l1 <= H:
        ans += l2
    else:
        print("impossible")
        exit()
print(ans)
