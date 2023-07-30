dirs = [(0,1), (1,0), (0,-1), (-1,0)]
delta = {
    'F': 0,
    'R': 1,
    'B': 2,
    'L': 3
}
def adv(p, dr):
    return (p[0]+dr[0], p[1]+dr[1])
TESTCASESWTFWHYIHAVETOPRINTTHIS = int(input())
print(TESTCASESWTFWHYIHAVETOPRINTTHIS)
for _ in range(TESTCASESWTFWHYIHAVETOPRINTTHIS):
    crdr = (0,1)
    s = input()
    pos = (0,0)
    inside = set()
    inside.add(pos)
    for c in s:
        crdr = dirs[(dirs.index(crdr)+delta[c])%4]
        pos = adv(pos, crdr)
        inside.add(pos)

    mini = min(i for i,j in inside)
    minj = min(j for i,j in inside)
    maxi = max(i for i,j in inside)
    maxj = max(j for i,j in inside)

    w = maxj+2
    h = maxi - mini + 3

    grid = [['#' for i in range(w)] for j in range(h)]

    print(h,w)
    for i,j in inside:
        grid[i - mini + 1][j - minj] = '.'
    print("\n".join("".join(row) for row in grid))
