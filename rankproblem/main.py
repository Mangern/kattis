n,q=map(int,input().split())

ans = list(range(1,n+1))

for _ in range(q):
    a,b=input().split()

    a = int(a[1:])
    b = int(b[1:])

    ia = ans.index(a)
    ib = ans.index(b)

    if ia < ib:
        continue

    ans.pop(ib)
    ans.insert(ia,b)

print(" ".join(f"T{x}" for x in ans))
