ans = 1
MOD = 10**9+7
for _ in range(int(input())):
    ans *= int(input()) % MOD
    ans %= MOD
print(ans)
