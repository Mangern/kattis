H, W = map(int,input().split())

board = []

for i in range(H):
    board.append([c for c in input()])
    assert len(board[-1]) == W, "Missed some chars!"

ids = [[0 for j in range(W)] for i in range(H)]
im_ptr = 1

good = set([ord('?'), ord('!'), ord(','), ord('.'), ord(' ')] + [i for i in range(ord('0'),ord('9')+1)] + [i for i in range(ord('a'), ord('z')+1)]+[i for i in range(ord('A'),ord('Z')+1)])

is_ad = set()

child = {}

for i in range(H):
    for j in range(W):
        if board[i][j] == '+':
            if i > 0 and board[i-1][j] == '+':
                ids[i][j] = ids[i-1][j]
            elif j > 0 and board[i][j-1] == '+':
                ids[i][j] = ids[i][j-1]
            else:
                parent = 0 
                if i > 0:
                    parent = ids[i-1][j]
                if j > 0:
                    parent = ids[i][j-1]

                if parent not in child:
                    child[parent] = []
                child[parent].append(im_ptr)

                ids[i][j] = im_ptr
                im_ptr += 1
        else:
            if i == 0 or j == 0:
                continue
            ids[i][j] = min(ids[i-1][j],ids[i][j-1])
            if ids[i][j] > 0 and ord(board[i][j]) not in good:
                is_ad.add(ids[i][j])

def dfs(u, ad = False):
    if u in is_ad:
        ad = True
    if ad:
        is_ad.add(u)

    if u in child:
        for v in child[u]:
            dfs(v, ad)

dfs(0)

for i in range(H):
    for j in range(W):
        if ids[i][j] in is_ad:
            board[i][j] = " "
    print("".join(board[i]))
