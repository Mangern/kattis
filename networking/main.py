n,k=map(int,input().split())
poss={}
for _ in range(n):
    d,s=input().split()
    d = int(d)
    if s not in poss:
        poss[s] = []
    poss[s].append(d)
name=list(poss.keys())
m=len(name)

dp=[[0]*(k+1) for _ in range(m+1)]

for i in range(1,m+1):
    for j in range(0,k+1):
        dp[i][j] = dp[i-1][j]
        for x in poss[name[i-1]]:
            if x <= j:
                dp[i][j] = max(dp[i][j], dp[i-1][j-x] + x)
print(dp[m][k])
