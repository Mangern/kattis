from math import pi, sqrt
m,n,q=map(int,input().split())

part = [0 for i in range(q)]

for i in range(q):
    x,y,s=input().split()
    x,y=int(x)-1,int(y)-1
    s = 1 if s == '-' else -1

    part[i] = (y,x,s)

grid = [['.' for j in range(m)] for i in range(n)]
pos = ['%','X','x']
neg = ['0','O','o']

for i in range(n):
    for j in range(m):
        is_at = False
        sm = 0
        for x,y,s in part:
            if x == i and y == j:
                is_at = True
                break
            dst = sqrt((x-i)*(x-i)+(y-j)*(y-j))
            sm += s / dst
        
        if is_at:
            grid[i][j] = '+' if s < 0 else '-'
        elif sm >= 1 / (pi*pi*pi):
            if sm >= 1 / pi:
                grid[i][j] = pos[0]
            elif sm >= 1 / (pi*pi):
                grid[i][j] = pos[1]
            else:
                grid[i][j] = pos[2]
        elif sm <= -1 / (pi*pi*pi):
            if sm <= -1 / pi:
                grid[i][j] = neg[0]
            elif sm <= -1 / (pi*pi):
                grid[i][j] = neg[1]
            else:
                grid[i][j] = neg[2]

print("\n".join("".join(l) for l in grid))
