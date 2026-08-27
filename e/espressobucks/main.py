n, m = map(int,input().split())

grid = [[c for c in input()] for i in range(n)]

def has_nei(i,j):
    for ni,nj in [(i-1,j), (i+1,j), (i,j-1), (i,j+1)]:
        if ni < 0 or ni >= n or nj < 0 or nj >= m:
            continue
        if grid[ni][nj] == 'E':
            return True
    return False

for i in range(n):
    for j in range(m):
        if grid[i][j] != '.':
            continue
        if has_nei(i,j):
            continue
        grid[i][j] = 'E'


print("\n".join("".join(line) for line in grid))
