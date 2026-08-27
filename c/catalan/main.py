import sys

dp = [-1,1]

for i in range(2,5001):
    # dp[-1] = 1/i * nCr(2*(i-1) , i-1)
    # 1/(i+1) * nCr(2*i, i)
    # mul with 2
    # mul with 2i-1
    # div by i+1
    #  2n 2n-1 2n-2 ... n+1
    #   n   n-1  n-2  n-3


    # 2(n-1) 2(n-1)-1 ... n
    #  n-1   n-2    n-3 ...
    x = dp[-1]
    x *= 2
    x *= 2*i - 1
    x //= i+1
    dp.append(x)
for _ in range(int(input())):
    n = int(input())
    print(dp[n])
