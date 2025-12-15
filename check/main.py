def solve():
    board=[input() for _ in range(8)]

    ki,kj=0,0
    for i in range(8):
        for j in range(8):
            if board[i][j] == 'K':
                ki,kj=i,j

    # Pawn check
    if ki>0 and (kj > 0 and board[ki-1][kj-1] == 'p' or kj < 7 and board[ki-1][kj+1] == 'p'):
        return True

    # Bishop/Queen check
    ul=True
    ur=True
    dl=True
    dr=True
    for d in range(1,9):
        if ki - d >= 0 and kj - d >= 0 and ul:
            if board[ki-d][kj-d] in "bq":
                return True
            if board[ki-d][kj-d] != '.':
                ul = False
        if ki - d >= 0 and kj + d < 8 and ur:
            if board[ki-d][kj+d] in "bq":
                return True
            if board[ki-d][kj+d] != '.':
                ur = False

        if ki+d < 8 and kj - d >= 0 and dl:
            if board[ki+d][kj-d] in "bq":
                return True
            if board[ki+d][kj-d] != '.':
                dl = False

        if ki + d < 8 and kj + d < 8 and dr:
            if board[ki+d][kj+d] in "bq":
                return True
            if board[ki+d][kj+d] != '.':
                dr = False

    # Rook/Queen check
    up=True
    dw=True
    lf=True
    rg=True

    for d in range(1,9):
        if ki-d >= 0 and up:
            if board[ki-d][kj] in "rq":
                return True
            if board[ki-d][kj] != '.':
                up = False
        if ki+d < 8 and dw:
            if board[ki+d][kj] in "rq":
                return True
            if board[ki+d][kj] != '.':
                dw = False
        if kj-d >= 0 and lf:
            if board[ki][kj-d] in "rq":
                return True
            if board[ki][kj-d] != '.':
                lf = False
        if kj+d < 8 and rg:
            if board[ki][kj+d] in "rq":
                return True
            if board[ki][kj+d] != '.':
                rg = False
    # Knight
    for ni, nj in [
        (ki-2,kj-1),
        (ki-2,kj+1),
        (ki-1,kj-2),
        (ki-1,kj+2),
        (ki+1,kj-2),
        (ki+1,kj+2),
        (ki+2,kj-1),
        (ki+2,kj+1),
    ]:
        if ni < 0 or ni >= 8 or nj < 0 or nj >= 8:
            continue
        if board[ni][nj] == 'n':
            return True
    return False
for _ in range(int(input())):
    if _ > 0:
        input()
    print("Yes" if solve() else "No")
