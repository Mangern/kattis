w,h,d=map(int,input().split())
grid = [input() for _ in range(h)]
loca = (0,0)
locb = (0,0)
for i in range(h):
    for j in range(w):
        if grid[i][j] == '@':
            loca = (i,j)
        if grid[i][j] == 'J':
            locb = (i,j)
print("no jumpscares here" if (loca[0] - locb[0])**2 + (loca[1]-locb[1])**2 > d**2 else "the guide is right")
