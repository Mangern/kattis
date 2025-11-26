def ncr(n,r):
    res = 1
    for i in range(1,n+1):
        res *= i
    for i in range(1,r+1):
        res //= i
    for i in range(1,n-r+1):
        res //= i
    return res

dpa = [[0]*19 for _ in range(19)]
dpa[0][0] = 1

for i in range(1,len(dpa)):
    dpa[i][0] = 1
    for j in range(1,i+1):
        if j == i:
            dpa[i][j] = dpa[i][j-1]
        else:
            dpa[i][j] = dpa[i-1][j] + dpa[i][j-1]

a,b,c=map(int,input().split())
print(ncr(b+c,c)*dpa[a][a])
