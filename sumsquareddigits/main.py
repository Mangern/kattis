for _ in range(int(input())):
    k,b,n = map(int,input().split())
    ans = 0
    pw = 1

    while pw <= n:
        pw *= b

    while pw:
        x = n//pw
        ans += x * x
        n -= x * pw
        pw //= b
    print(f"{k} {ans}")
