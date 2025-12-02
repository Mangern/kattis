has=set()
n,m=map(int,input().split())
for _ in range(n):
    a=list(map(int,input().split()))
    for x in a[1:]:
        has.add(x)
print("Jebb" if len(has) == m else "Neibb")
