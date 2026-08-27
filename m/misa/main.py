n,m=map(int,input().split())
grid = [input() for i in range(n)]

neis = lambda i,j: [(i-1,j-1), (i-1,j), (i-1,j+1), (i,j-1), (i,j+1), (i+1,j-1), (i+1, j), (i+1,j+1)]
sm = 0
mx = 0
for i in range(n):
    for j in range(m):
        cur = 0
        for di,dj in neis(i,j):
            if di < 0 or di >= n or dj < 0 or dj >= m:
                continue
            if grid[di][dj] == 'o':
                cur += 1
        if grid[i][j] == 'o':
            sm += cur
        else:
            mx = max(mx,cur)

sm //= 2
sm += mx
print(sm)

