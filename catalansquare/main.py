dp = [1]

for n in range(0, 5001):
    dp.append((4 * n + 2) * dp[-1] // (n + 2))

n = int(input())
s = 0
for k in range(n+1):
    s += dp[k] * dp[n - k]

print(s)
