n,m=map(int,input().split())
dp=[[False]*(m+1) for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(1, m+1):
        for dj in range(1, j):
            if not dp[i][dj] and not dp[i][j-dj]:
                dp[i][j] = True
        for di in range(1, i):
            if not dp[di][j] and not dp[i-di][j]:
                dp[i][j] = True
print("A" if dp[n][m] else "B")
