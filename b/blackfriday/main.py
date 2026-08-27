input()
a = list(map(int,input().split()))

cnt = dict()
for x in a:
    if x not in cnt:
        cnt[x] = 0
    cnt[x] += 1

ans = 0
for x in cnt:
    if cnt[x] == 1:
        ans = max(ans,x)

if ans == 0:
    ans = "none"
else:
    ans = a.index(ans)+1

print(ans)

