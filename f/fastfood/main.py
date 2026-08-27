for _ in range(int(input())):
    n,m=map(int,input().split())
    xs = [[int(x)-1 for x in input().split()] for i in range(n)]
    cnts = [int(x) for x in input().split()]
    ans = 0
    for x in xs:
        p = x.pop()+1
        req = x[1:]
        mncnt = cnts[req[0]]
        for y in req:
            mncnt = min(mncnt,cnts[y])
        ans += mncnt * p
    print(ans)

