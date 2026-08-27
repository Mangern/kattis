h1,w1,h2,w2=map(int,input().split())
grid=[['+']*w1 for _ in range(h1)]

for i in range(h2):
    for j in range(w2):
        grid[1+i][1+j] = '-'
for row in grid:
    print("".join(row))
