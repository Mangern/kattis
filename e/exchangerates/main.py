while True:
    n=int(input())
    if n == 0:
        break

    dp = [[0]*(n+1) for _ in range(2)]
    # dp[0][i]: Max money (in us dollars) after day i if doing canada -> US on day i
    # dp[1][i]: Same but if doing US -> canada
    dp[1][0] = 100000

    for i in range(1, n+1):
        val=float(input())

        for j in range(i):
            dp[0][i] = max(dp[0][i], int(dp[1][j] / val * 0.97))
        for j in range(i):
            dp[1][i] = max(dp[1][i], int(dp[0][j] * val * 0.97))

    print(f"{max(dp[1])/100.0:.02f}")
