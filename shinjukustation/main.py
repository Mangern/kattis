def sexs():
    h,m,s=map(int,input().split(":"))
    return h * 3600 + m * 60 + s
n,m=map(int,input().split())
arr=[sexs() for _ in range(n)]
dep=[sexs() for _ in range(n)]
l=int(input())

ans=-1
for a in arr:
    for d in dep:
        if d >= a + l:
            if ans == -1:
                ans = 10**17
            ans = min(ans, d - a)

print(ans)
