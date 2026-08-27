s,m,n=map(int,input().split())
for _ in range(n):
    ws=input().split()
    if ws[0] == "DRIP":
        d=int(ws[1])
        p=int(ws[2])
        div=d*s
        cnt=div//p
        s += cnt
        m += div-cnt*p
    else:
        p=int(ws[1])
        cnt=m//p
        s += cnt
        m -= cnt * p
print(s)
print(m)
