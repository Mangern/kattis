n,k=map(int,input().split())
dp=[0]*(n+1)
MOD=10**9+7
dp[0] = 1
fac = [0]*(n+1)
ifac = [0]*(n+1)
fac[0] = 1
for i in range(1,n+1):
    fac[i]=fac[i-1]*i%MOD

ifac[n] = pow(fac[n], MOD-2, MOD)

for i in range(n-1, -1, -1):
    ifac[i] = ifac[i+1] * (i + 1) % MOD

for i in range(1,n+1):
    for j in range(1,min(i,k)+1):
        nck = fac[i] * ifac[i-j] * ifac[j] % MOD
        dp[i] += nck * dp[i-j] % MOD
        dp[i] %= MOD

print(dp[n])
