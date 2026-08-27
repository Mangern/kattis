evt=[]
for _ in range(int(input())):
    a,b,c,d=input().split()
    b,c,d=map(int,[b,c,d])
    if a=="MISS":
        c = -c
        d = -d
    evt.append((b,c,d))
k=int(input())
ans1=0
ans2=0
for a,b,c in evt:
    if a < k:
        ans1 += b
        ans2 += c
print(ans1,ans2)

