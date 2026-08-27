import random

def gen(n, m):
    grid = []
    cnt = 1
    for i in range(n):
        grid.append([])
        for j in range(m):
            grid[-1].append(cnt)
            cnt += 1

    li = n - 1
    lj = m - 1

    for _ in range(1000):
        moves = []
        if li < n - 1:
            moves.append((li+1,lj))
        if lj < m - 1:
            moves.append((li,lj+1))
        if li > 0:
            moves.append((li-1, lj))
        if lj > 0:
            moves.append((li, lj - 1))

        mi, mj = random.choice(moves)
        grid[li][lj], grid[mi][mj] = grid[mi][mj], grid[li][lj]
        li, lj = mi, mj

    while li < n - 1:
        mi = li + 1
        mj = lj
        grid[li][lj], grid[mi][mj] = grid[mi][mj], grid[li][lj]
        li, lj = mi, mj

    while lj < m - 1:
        mi = li
        mj = lj + 1
        grid[li][lj], grid[mi][mj] = grid[mi][mj], grid[li][lj]
        li, lj = mi, mj

    print(f"{n} {m}")
    for row in grid:
        print(" ".join(map(str, row)))

if __name__ == "__main__":
    gen(10, 10)
