for _ in range(int(input())):
    d,m=map(int,input().split())
    ds = [int(x) for x in input().split()][::-1]

    cur = 6
    # friday==4
    curd = 1
    ans = 0
    while len(ds):
        if curd == 13 and cur == 4:
            ans += 1

        if curd == ds[-1]:
            curd = 1
            ds.pop()
        else:
            curd += 1
        cur += 1
        cur %= 7
    print(ans)
