s,c,k=map(int,input().split())
a = list(map(int, input().split()))

a.sort()
ans = 0

cnt = c
cur_lo = a[0]
for x in a:
    if x - cur_lo > k or cnt == c:
        cnt = 1
        cur_lo = x
        ans += 1
    else:
        cnt += 1

print(ans)
