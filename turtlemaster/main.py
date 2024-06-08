def bug():
    print("Bug!")
    exit(0)

grid = [list(input()) for _ in range(8)]

r = 7
c = 0
dr = 0
dc = 1

grid[r][c] = '.'

for ch in input():
    if ch == "F":
        nr = r + dr
        nc = c + dc
        if nr < 0 or nr >= 8 or nc < 0 or nc >= 8:
            bug()
        if grid[nr][nc] in "IC":
            bug()

        r = nr
        c = nc
    elif ch == "R":
        dr, dc = dc, dr
        dc *= -1
    elif ch == "L":
        dr, dc = dc, dr
        dr *= -1
    else:
        nr = r + dr
        nc = c + dc
        if nr < 0 or nr >= 8 or nc < 0 or nc >= 8:
            bug()
        if grid[nr][nc] != "I":
            bug()
        grid[nr][nc] = "."

if grid[r][c] != "D":
    bug()

print("Diamond!")
