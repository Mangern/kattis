a,b = map(int,input().split())

ans = 0

while b < a:
    if a & 1:
        a += 1
    else:
        a >>= 1
    ans += 1

ans += b - a
print(ans)

