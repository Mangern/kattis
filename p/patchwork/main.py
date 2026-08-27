r,c=map(int,input().split())

grid = [['.' for j in range(c)] for i in range(r)]

n = int(input())

rs = [0 for i in range(n)]
cs = [0 for i in range(n)]
patch = [[""] for i in range(n)]
for i in range(n):
    rs[i],cs[i] = map(int,input().split())
    patch[i] = [input() for j in range(rs[i])]

m = int(input())

for k in range(m):
    q,t,p=map(int,input().split())
    p -= 1

    for i in range(rs[p]):
        if q+i >= r:
            break
        for j in range(cs[p]):
            if t+j >= c:
                break
            grid[q+i][t+j] = patch[p][i][j]

print("\n".join("".join(l) for l in grid))

