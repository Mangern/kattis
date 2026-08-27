n,m=map(int,input().split())

a = [list(map(int,input().split())) for i in range(n)]

for i in range(n):
    for j in range(m):
        if i and j:
            a[i][j] += max(a[i-1][j],a[i][j-1])
        elif i:
            a[i][j] += a[i-1][j]
        elif j:
            a[i][j] += a[i][j-1]

print(" ".join(str(a[i][m-1]) for i in range(n)))
