import sys
MOD = 10**9 + 7

sys.setrecursionlimit(10005)

dp = [[-1 for i in range(10001)],[-1 for i in range(10001)]]

def solve(n, k):
    if n == 1:
        return 1

    if dp[k][n] != -1:
        return dp[k][n]

    ans = 0
    if k == 0:
        ans = solve(n-1, 0)+solve(n-1, 1)
    else:
        ans = solve(n-1, 0)
    if ans >= MOD:
        ans -= MOD
    dp[k][n] = ans
    return ans

for _ in range(int(input())):
    n = int(input())

    print((solve(n, 0)+solve(n, 1))%MOD)
