cnt={}
input()
for x in map(int,input().split()):
    cnt[x] = cnt.get(x, 0) + 1

ans=0
for k, v in cnt.items():
    sz=k+1
    ans += (v + sz - 1) // sz * sz
print(ans)
