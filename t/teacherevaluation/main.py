n,p=map(int,input().split())

a=list(map(int,input().split()))

if p == 100:
    if min(a) < 100:
        print("impossible")
    else:
        print(0)
    exit()

ans=10**9

s=sum(a)
for x in range(0,101):
    top = p * (n + 1) - s - x
    if top >= 0 and top % (100 - p) == 0:
        h = top // (100 - p)
        ans = min(ans, h + 1)
assert ans < 10**9
print(ans)
