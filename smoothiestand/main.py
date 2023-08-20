k,r=map(int,input().split())
cap = list(map(int,input().split()))

ans = 0
for _ in range(r):
    a = list(map(int,input().split()))
    cost = a.pop()
    can = min(c//x for c,x in zip(cap,a) if x)
    ans = max(ans, can * cost)
print(ans)
