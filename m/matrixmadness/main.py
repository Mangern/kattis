n,m=map(int,input().split())
grid = [list(map(int,input().split())) for _ in range(n)]
for i in range(n):
    for j in range(m):
        for p in range(n):
            for q in range(m):
                if (i,j) == (p,q):
                    continue
                if grid[i][j] == grid[p][q] and abs(i-p)+abs(j-q) <= grid[i][j]:
                    print("INVALID")
                    exit()
print("VALID")
