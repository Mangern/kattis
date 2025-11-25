n,k=map(int,input().split())
l=list(map(int,input().split()))
fail=False
for x,y in zip(l,l[1:]):
    if y - x > k:
        fail = True
print("POSSIBLE" if not fail else "BUG REPORT")
