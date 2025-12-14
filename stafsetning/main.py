n,m,k=map(int,input().split())
s=sum(map(int,input().split()))
perd=k//m

if perd==0:
    print(":(")
else:
    print((s+perd-1)//perd)
