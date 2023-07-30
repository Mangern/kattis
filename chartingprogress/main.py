from sys import stdin

def solve(grid):
    n = len(grid)
    m = len(grid[0])
    
    def geth(i):
        for j in range(n):
            if grid[j][i]=='*':
                return n-j
    idxs = [i for i in range(m)]
    
    idxs.sort(key=geth)
    for i in range(n):
        for j in range(m):
            print(grid[i][idxs[j]],end="")
        print()

lines = []

s_1 = False
for line in stdin:
    if len(line.strip())==0:
        if s_1:
            print()
        solve(lines)
        lines = []
        s_1 = True
    else:
        lines.append(line.strip())
print()
solve(lines)
