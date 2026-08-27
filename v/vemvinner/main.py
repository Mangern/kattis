from itertools import chain
board = ["".join(input().split()) for i in range(3)]

ss = list(chain(board,
           ("".join(s[i] for s in board) for i in range(3)),
           ("".join(board[i][i] for i in range(3)),), 
           ("".join(board[i][2-i] for i in range(3)),)))

print("Johan" if "XXX" in ss else ("Abdullah" if "OOO" in ss else "ingen"), "har vunnit")
