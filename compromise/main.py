for _ in range(int(input())):
    n,m=map(int,input().split())

    s = [input() for i in range(n)]
    ans = ['0' for i in range(m)]

    for i in range(m):
        cnt0 = 0
        for j in range(n):
            if s[j][i] == '0':
                cnt0 += 1
        if 2*cnt0 < n:
            ans[i] = '1'
    print("".join(ans))
