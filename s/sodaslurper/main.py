a,b,c = map(int,input().split())

a += b

ans = 0

while a >= c:
    a -= c
    a += 1
    ans += 1

print(ans)
