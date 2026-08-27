alph=[
    "qwertasdfgzxcvb ",
    "yuiophjklnm,. "
]
t,s=map(int,input().split())

txt=input()
n=len(txt)

# dp[s][i]: time to finish 0..i given that you end on hand s
dp = [[0]*n, [0]*n]

for i in range(n):
    for j in range(2):
        if txt[i] in alph[j]:
            dp[j][i] = t
        else:
            dp[j][i] = 1000

        if i > 0:
            dp[j][i] += min(dp[1-j][i-1] + s, dp[j][i-1])

print(min(dp[0][n-1], dp[1][n-1]))
