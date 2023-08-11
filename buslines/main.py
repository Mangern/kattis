n, m = map(int,input().split())

if n-1 <= m <= 2 * n - 3:
    ans = []
    s = 1
    msm = 0
    while len(ans) < m:
        for i in range(s+1,n+1):
            if s+i <= msm:
                continue
            ans.append((s,i))
            msm = s+i
            if len(ans) == m:
                break
        s += 1
    for x,y in ans:
        print(x,y)
else:
    print(-1)
