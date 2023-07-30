pa,ka,pb,kb,n = map(int,input().split())

ans = 1000000000000000
for a in range(n+1):
    b = n - a

    na = (a+ka-1)//ka
    nb = (b+kb-1)//kb
    sm = na*pa+nb*pb
    if sm < ans:
        ans = sm
        sa=na
        sb=nb

print(f"{sa} {sb} {ans}")
