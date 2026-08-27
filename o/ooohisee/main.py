r,c=map(int,input().split())
grid = [input() for _ in range(r)]

ans=[]
for i in range(1,r-1):
    for j in range(1,c-1):
        if grid[i][j] == '0':
            bad = False
            for ni in range(i-1,i+2):
                for nj in range(j-1,j+2):
                    if (ni,nj) != (i,j) and grid[ni][nj] != 'O':
                        bad = True
            if not bad:
                ans.append((i+1,j+1))

if len(ans) == 0:
    print("Oh no!")
elif len(ans) == 1:
    print(*ans[0])
else:
    print(f"Oh no! {len(ans)} locations")
