n,m=map(int,input().split())

ans = 0

while m:
    if m & 1:
        ans += 1
    m >>= 1
print(ans)
