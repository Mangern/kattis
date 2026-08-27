n,m=map(int,input().split())
grid=[input() for _ in range(n)]
ans=[]
for j in range(m):
    for i in range(n):
        if grid[i][j] != '.':
            ans.append(grid[i][j])
print("".join(ans))
