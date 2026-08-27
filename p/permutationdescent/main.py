MOD = 1001113

ncr = [[0 for i in range(105)] for j in range(105)]

def nCr(n,k):
    global ncr
    if k > n or k < 0:
        return 0
    return ncr[n][k]

ncr[0][0] = 1
for i in range(1,105):
    for j in range(i+1):
        ncr[i][j] = nCr(i-1,j-1)+nCr(i-1,j)
        if ncr[i][j] >= MOD:
            ncr[i][j] -= MOD

dp = [[-1 for i in range(105)] for j in range(105)]
def pdc(n,v):
    if v == 0:
        return 1
    if v >= n:
        return 0
    if v < 0:
        return 0

    if dp[n][v] != -1:
        return dp[n][v]

    ans = pdc(n-1,v)
    for i in range(1,n):
        for vi in range(v):
            ans += nCr(n-1,i)*pdc(i,vi)*pdc(n-i-1,v-vi-1)
            ans %= MOD
    dp[n][v] = ans
    return ans

for _ in range(int(input())):
    k,n,v=map(int,input().split())
    print(f"{k} {pdc(n,v)}")
