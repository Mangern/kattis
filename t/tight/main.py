from sys import stdin

for line in stdin:
    k, n = map(int, line.split())

    dp = [[0 for i in range(k+1)] for j in range(n+1)]

    for i in range(k+1):
        dp[1][i] = 1

    for i in range(2, n+1):
        for j in range(k+1):
            for z in [j-1, j, j+1]:
                if 0 <= z <= k:
                    dp[i][j] += dp[i-1][z]
    
    print(100 * (sum(dp[n]) / (k+1)**n))
