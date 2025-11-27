n,c=map(int,input().split())
mnt=[10**10]*24
for _ in range(n):
    t,p=map(int,input().split())
    mnt[t] = min(mnt[t], p)
prs = list(enumerate(mnt))
prs.sort(key=lambda t: t[1])
ans = 0
for _,x in prs:
    if x > c:
        break
    c -= x
    ans += 1
print(ans)
