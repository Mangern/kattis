n,k=map(int,input().split())

a = list(map(int,input().split()))
for x in a:
    if x <= k:
        k -= x
        print("1",end="")
    else:
        print("0",end="")
print()
