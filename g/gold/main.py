from itertools import product
from queue import Queue

m,n=map(int,input().split())
board = [input() for i in range(n)]

pi,pj = [(i,j) for i, j in product(range(n), range(m)) if board[i][j] == 'P'][0]

q = Queue()
vis = set()

q.put((pi,pj))
vis.add((pi,pj))

ans = 0

def live_neighbors(i,j):
    for ni,nj in [(i-1,j),(i+1,j),(i,j-1),(i,j+1)]:
        if ni < 0 or ni >= n or nj < 0 or nj >= m:
            continue
        if board[ni][nj] == '#':
            continue
        if (ni,nj) in vis:
            continue
        yield (ni,nj)


while not q.empty():
    i,j = q.get()
    if board[i][j] == 'G':
        ans += 1
    has_trap = False
    for ni,nj in live_neighbors(i,j):
        if board[ni][nj] == 'T':
            has_trap = True
    if has_trap:
        continue
    for ni,nj in live_neighbors(i,j):
        vis.add((ni,nj))
        q.put((ni,nj))

print(ans)
