n,lph=map(int,input().split())
tot=lph*5
loc=[int(input()) for _ in range(n)]
loc.sort()
W=sum(loc)
dp = [[0]*(W+1) for _ in range(n+1)]
for i in range(n):
    for w in range(W+1):
        dp[i+1][w] = dp[i][w]
        if w >= loc[i]:
            dp[i+1][w] = max(dp[i+1][w], dp[i][w-loc[i]] + 1)
print(dp[n][min(tot, W)])
