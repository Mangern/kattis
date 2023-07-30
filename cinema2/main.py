n,m=map(int,input().split())
a = list(map(int,input().split()))

ans = 0
for i in range(m):
    if a[i] > n:
        ans += 1
        n = -10000
    else:
        n -= a[i]
print(ans)
