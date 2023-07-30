n,m=map(int,input().split())

i = 1
cnt = 0
while i * i <= m:
    if m % i == 0:
        if i <= n and (m//i)<=n:
            cnt += 1
            if i * i != m:
                cnt += 1
    i += 1

print(cnt)


