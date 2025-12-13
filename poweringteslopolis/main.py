n=int(input())
m=int(input())
grid=[input() for _ in range(n)]
pw=[[False]*m for _ in range(n)]
for i in range(n):
    for j in range(m):
        if grid[i][j] == 'T':
            for ni in range(max(0, i-1), min(n,i+2)):
                for nj in range(max(0,j-1),min(m,j+2)):
                    pw[ni][nj] = True
ans=[]
for i in range(n):
    for j in range(m):
        if not pw[i][j]:
            ans.append((i,j))
print(not ans)
for x,y in ans:
    print(x,y)
