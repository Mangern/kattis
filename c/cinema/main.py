n,m=map(int,input().split())

ans = 0
for x in map(int,input().split()):
    if x > n:
        ans += 1
        continue
    n -= x
print(ans)
