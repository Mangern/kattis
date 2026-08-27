from collections import deque

q = deque()

adj = dict()

n, m = map(int,input().split())

grid = [input() for i in range(n)]

for i in range(n):
    for j in range(m):
        adj[(i,j)] = []
        dig = int(grid[i][j])

        for ni,nj in [(i-dig,j),(i+dig,j),(i,j-dig),(i,j+dig)]:
            if ni < 0 or ni >= n or nj < 0 or nj >= m:
                continue
            adj[(i,j)].append((ni,nj))

q.append((0,0))
dist = [[-1 for j in range(m)] for i in range(n)]

dist[0][0] = 0

while len(q):
    i,j = q.popleft()

    for ni, nj in adj[(i,j)]:
        if dist[ni][nj] == -1:
            dist[ni][nj] = dist[i][j] + 1
            q.append((ni,nj))

print(dist[n-1][m-1])

