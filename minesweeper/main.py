n,m,k=map(int,input().split())
grid=[['.']*m for _ in range(n)]
for _ in range(k):
    r,c=map(int,input().split())
    grid[r-1][c-1]='*'
for row in grid:
    print("".join(row))
