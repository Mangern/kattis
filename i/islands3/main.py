n,m = map(int,input().split())
def cti(i,j):
    return i * m + j
grid = [input().strip() for i in range(n)]
par = [i for i in range(n*m)]

def find_par(i):
    if i == par[i]:
        return i
    par[i] = find_par(par[i])
    return par[i]

has_land = [False for i in range(n*m)]
def join(i,j):
    i = find_par(i)
    j = find_par(j)
    if i != j:
        if has_land[i]:
            has_land[j] = True
        par[i] = j
for i in range(n):
    for j,c in enumerate(grid[i]):
        if c == "L":
            has_land[cti(i,j)] = True
        if c != "W":
            if i > 0 and grid[i-1][j] != "W":
                join(cti(i,j),cti(i-1,j))
            if j > 0 and grid[i][j-1] != "W":
                join(cti(i,j),cti(i,j-1))
ans = set(filter(lambda i: has_land[i], map(find_par, range(n*m))))
print(len(ans))
