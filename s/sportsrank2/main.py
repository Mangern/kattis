for _ in range(int(input())):
    a=list(map(int,input().split()[1:]))
    a.sort(reverse=True)
    rnk=[1]
    for prv,cur in zip(a,a[1:]):
        if cur == prv:
            rnk.append(rnk[-1])
        else:
            rnk.append(len(rnk)+1)
    dns=[1]
    for prv, cur in zip(a, a[1:]):
        if cur ==prv:
            dns.append(dns[-1])
        else:
            dns.append(dns[-1]+1)
    ans=0
    for x,y in zip(rnk,dns):
        if y<x:
            ans +=1
    print(ans)
