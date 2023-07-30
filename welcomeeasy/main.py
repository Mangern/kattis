for tc in range(1,int(input())+1):
    print(f"Case #{tc}: ",end=" ")
    s = input()

    n = len(s)
    target = "welcome to code jam"
    m = len(target)

    dp = [0 if s[i] != 'w' else 1 for i in range(n)]
    for j in range(1,m):
        sm = 0
        ndp = [0 for i in range(n)]
        for i in range(n):
            if s[i] == target[j]:
                ndp[i] = sm%10000
            sm += dp[i]
            sm %= 10000
        dp = ndp

    print(f"{(sum(dp)%10000):04d}")
