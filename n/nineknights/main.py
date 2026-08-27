n = 5
board = [input() for i in range(n)]

cnt_k = 0

for i in range(n):
    for j in range(n):
        if board[i][j] == 'k':
            cnt_k += 1
            for ni,nj in [(i-2,j-1), (i-2,j+1), (i+2,j-1), (i+2, j+1), (i-1, j-2), (i-1, j+2), (i+1, j-2), (i+1, j+2)]:
                if ni < 0 or ni >= n or nj < 0 or nj >= n:
                    continue
                if board[ni][nj] == 'k':
                    print("invalid")
                    exit(0)

print("valid" if cnt_k == 9 else "invalid")

