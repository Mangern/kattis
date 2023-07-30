n,m=map(int,input().split())
grid = [list(input()) for i in range(n)]

while True:
    ch = False
    for i in range(n-1):
        for j in range(m):
            if grid[i][j] == 'V':
                if grid[i+1][j] == '#':
                    if j > 0 and grid[i][j-1] == '.':
                        grid[i][j-1] = 'V'
                        ch = True
                    if j < m - 1 and grid[i][j+1] == '.':
                        grid[i][j+1] = 'V'
                        ch = True
                elif grid[i+1][j] == '.':
                    grid[i+1][j] = 'V'
                    ch = True
    if not ch:
        break
print("\n".join("".join(s) for s in grid))
