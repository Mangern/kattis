for _ in range(int(input())):
    k,*a=list(map(int,input().split()))
    l = []

    ans = 0
    for x in a:
        for i in range(len(l)+1):

            if i == len(l) or l[i] > x:
                break
        ans += len(l)-i
        l.insert(i,x)
    print(k,ans)
