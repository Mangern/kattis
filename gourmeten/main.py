m = int(input())
n = int(input())
a = [int(input()) for _ in range(n)]

dp = [0 for i in range(m+1)]
dp[0] = 1


for i in range(1,m+1):
    for x in a:
        if x <= i:
            dp[i] += dp[i-x]

print(dp[m])
