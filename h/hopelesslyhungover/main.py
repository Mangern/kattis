n,k,m,d=map(int,input().split())

if 5 * k - 2 * m <= 0 and 5 * k < n:
    print("impossible")
    exit()

cur = 0
ans = 0

while cur < n:
    if d <= 5:
        cur += k
    else:
        cur -= m
        if cur < 0:
            cur = 0
    d += 1
    ans += 1
    if d > 7:
        d = 1
print(ans)
