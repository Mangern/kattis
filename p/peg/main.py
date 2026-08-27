board = [list(input()) for i in range(7)]
ans = 0

for i in range(7):
    for j in range(7):
        if board[i][j] == '.':
            for di,dj in [(i-2,j),(i+2,j),(i,j-2),(i,j+2)]:
                if di < 0 or di >= 7 or dj < 0 or dj >= 7:
                    continue
                ddi = (i+di)//2
                ddj = (j+dj)//2
                if board[ddi][ddj] == 'o' and board[di][dj] == 'o':
                    ans += 1
print(ans)
