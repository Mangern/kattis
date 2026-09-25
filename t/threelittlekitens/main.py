n=int(input())
m=int(input())
grid=[input() for _ in range(n)]

ans=[]
for c in "RGB":
    mits=[]
    pos=set()
    for i in range(n):
        for j in range(m):
            if grid[i][j] == c:
                neis = 0
                for ni in [i-1, i, i+1]:
                    for nj in [j-1, j, j+1]:
                        if ni == i and nj == j:
                            continue
                        if ni < 0 or ni >= n or nj < 0 or nj >= m:
                            continue
                        if grid[ni][nj] == c:
                            neis += 1
                if neis == 1:
                    mits.append((i+1,j+1))
                    pos.add((i+1,j+1))
                elif neis == 2:
                    pos.add((i+1,j+1))
    assert len(mits) == 2
    mits.sort()
    ans.append([min(pos), mits[0], mits[1]])

for p1, p2, p3 in ans:
    print(*p1, *p2, *p3)
