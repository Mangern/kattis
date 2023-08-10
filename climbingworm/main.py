a,b,h=map(int,input().split())

y = 0
ans = 0
while True:
    y += a
    ans += 1
    if y >= h:
        break
    y -= b

print(ans)

