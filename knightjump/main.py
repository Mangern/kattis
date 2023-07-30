from math import inf
from collections import deque
def main():
    n = int(input())
    board = list(map(lambda i: input().strip(),range(n)))

    def cti(i,j):
        return i * n + j

    adj = [[] for i in range(n*n)]
    dist = [inf for i in range(n*n)]


    s = 0
    for i in range(n):
        for j in range(n):
            if board[i][j] == 'K':
                s = cti(i,j)
            for ni,nj in [(i+2,j+1),(i+2,j-1),(i-2,j+1),(i-2,j-1),(i+1,j+2),(i+1,j-2),(i-1,j+2),(i-1,j-2)]:
                if not (0 <= ni < n) or not (0 <= nj < n):
                    continue
                if board[ni][nj] == '#':
                    continue
                adj[cti(ni,nj)].append(cti(i,j))

    q = deque()
    dist[s] = 0
    q.append(s)
    while len(q):
        u = q.popleft()
        for v in adj[u]:
            if dist[u] + 1 < dist[v]:
                dist[v] = dist[u] + 1
                q.append(v)
    if dist[0] == inf:
        dist[0] = -1
    print(dist[0])

if __name__ == "__main__":
    main()

