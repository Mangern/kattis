def is_prime(n):
    if n < 2:
        return False
    for i in range(2, n):
        if i * i > n:
            break
        if n % i == 0:
            return False
    return True

def solve(grid, r = 0, c = 0):
    n = len(grid)
    m = len(grid[0])
    if r >= n:
        return 1
    sm = 0
    for k in range(10):
        grid[r][c] = k
        nr = r
        nc = c+1
        if nc >= m:
            nr += 1
            nc = 0
        a = int("".join(str(x) for x in grid[r][:c+1]))
        b = int("".join(str(grid[i][c]) for i in range(r+1)))
        if is_prime(a) and is_prime(b):
            sm += solve(grid, nr, nc)
        grid[r][c] = -1
    return sm


n, m = map(int,input().split())

grid = [[-1 for i in range(m)] for j in range(n)]

print(solve(grid))
