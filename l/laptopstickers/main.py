l,h,k = map(int,input().split())

res = [['_' for j in range(l)] for i in range(h)]

for _ in range(k):
    m,n,sj,si=map(int,input().split())

    for i in range(si,min(si+n,h)):
        for j in range(sj,min(sj+m,l)):
            res[i][j] = chr(_+ord('a'))

print("\n".join("".join(r) for r in res))
