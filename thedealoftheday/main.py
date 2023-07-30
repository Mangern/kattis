ar = list(map(int,input().split()))

k = int(input())

c = (1<<k)-1

ans = 0
while c < (1<<10):
    prod = 1

    for i in range(10):
        if c & (1<<i):
            prod *= ar[i]
    ans += prod

    a = c&(-c)
    b = a+c
    c = (c^b)//4//a|b

print(ans)
