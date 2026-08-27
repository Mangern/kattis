def main():
    n,m=map(int,input().split())

    a = [list(map(int,input().split())) for _ in range(n)]

    good = [x for row in a for x in row if x != -1]
    good.sort()

    def check(dias):
        cnt = 0
        idx = 0
        for dia in dias:
            here = good[idx:idx+len(dia)]

            for x in here:
                if x not in dia:
                    cnt += 1

            idx += len(dia)
        return cnt

    nw = []
    for i in range(n):
        dia = set() 
        for j in range(min(i+1,m)):
            dia.add(a[i-j][j])
        if -1 in dia:
            dia.remove(-1)
        nw.append(dia)

    for j in range(1,m):
        dia = set() 
        for i in range(min(m-j, n)):
            dia.add(a[n-1-i][j+i])
        if -1 in dia:
            dia.remove(-1)
        nw.append(dia)

    ans = check(nw)
    ans = min(ans,check(nw[::-1]))

    se = []
    for j in range(m):
        dia = set()
        for i in range(min(j+1,n)):
            dia.add(a[n-1-i][j-i])
        if -1 in dia:
            dia.remove(-1)
        se.append(dia)

    for i in range(n-2,-1,-1):
        dia = set()
        for j in range(min(m,i+1)):
            dia.add(a[i-j][m-1-j])
        if -1 in dia:
            dia.remove(-1)
        se.append(dia)

    ans = min(ans,check(se))
    ans = min(ans,check(se[::-1]))

    print(ans)

main()
