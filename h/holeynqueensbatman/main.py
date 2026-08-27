def valid(board, cols, r, c):
    n = len(board)
    for j in range(n):
        if j in cols:
            continue
        for i in range(r):
            if board[i][j] == 1:
                if (j == c) or ((i+j) == (r+c)) or ((i-j) == (r-c)):
                    return False
    return True

def solve(r, c, board, rows, diup, didown):
    n = len(board)
    if c == n - 1:
        #print(np.matrix(board))
        return 1

    sm = 0

    rows.add(r)
    diup.add(r+c)
    didown.add(r-c)

    for i in range(n):
        if i in rows:
            continue
        if i+c+1 in diup:
            continue
        if i-c-1 in didown:
            continue
        if board[i][c+1] == -1:
            continue
        sm += solve(i,c+1,board,rows,diup,didown)

    rows.remove(r)
    diup.remove(r+c)
    didown.remove(r-c)

    return sm

while True:
    n,m=map(int,input().split())
    if not n+m:
        break

    board = [[0 for i in range(n)] for j in range(n)]
    for i in range(m):
        r,c = map(int,input().split())
        board[r][c] = -1

    ans = 0 
    rows = set()
    diup = set()
    didown = set()
    for r in range(n):
        if board[r][0] != -1:
            ans += solve(r, 0, board, rows, diup, didown)

    print(ans)
