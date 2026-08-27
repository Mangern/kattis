n = int(input())
ss = [0 for i in range(n)]
bs = [0 for i in range(n)]

for i in range(n):
    ss[i],bs[i] = map(int,input().split())

ans = -1
for mask in range(1,1<<n):
    ts = 1
    tb = 0
    for i in range(n):
        if mask & (1<<i):
            ts *= ss[i]
            tb += bs[i]
    if ans == -1:
        ans = abs(ts-tb)
    ans = min(ans,abs(ts-tb))

print(ans)
