n,m=map(int,input().split())
xs=list(map(int,input().split()))
ys=set(map(int,input().split()))
print(" ".join(map(str, (x for x in xs if x in ys))))
