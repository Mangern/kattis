for _ in range(int(input())):
    TC,n,m,k = map(int,input().split())

    def invalid(x):
        return (x - m) % k == 0

    dp = [-1 for i in range(n+1)]
    def calculate(x):
        if not x:
            return 1
        if dp[x] != -1:
            return dp[x]
        sum = 0
        for i in range(1,x+1):
            if invalid(i):
                continue
            sum += calculate(x-i)
        dp[x] = sum
        return sum
    print(TC, calculate(n))
