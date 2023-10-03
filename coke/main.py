def main():
    INF = 10**9
    dp = dict()
    def f(C, n1, n5, n10):
        if C == 0:
            return 0

        if (C, n1, n5, n10) in dp:
            return dp[(C, n1, n5, n10)]

        ans = INF

        if n1 >= 8:
            ans = min(ans, 8 + f(C-1, n1 - 8, n5, n10))
        if n1 >= 3 and n5 >= 1:
            ans = min(ans, 4 + f(C-1, n1 - 3, n5 - 1, n10))
        if n5 >= 2:
            ans = min(ans, 2 + f(C-1, n1 + 2, n5 - 2, n10))
        if n10 >= 1:
            ans = min(ans, 1 + f(C-1, n1 + 2, n5, n10 - 1))

        dp[(C, n1, n5, n10)] = ans
        return ans

    for _ in range(int(input())):
        C, n1, n5, n10 = map(int, input().split())
        print(f(C, n1, n5, n10))

    print(max(dp.keys(), key=lambda t: t[1]))

main()
