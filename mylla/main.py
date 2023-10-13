board = [input(), input(), input()]

if "OOO" in board or "OOO" in map(lambda l: "".join(l), zip(*board)):
    print("Jebb")
    exit()

if "".join([board[0][0], board[1][1], board[2][2]]) == "OOO":
    print("Jebb")
    exit()

if "".join([board[2][0], board[1][1], board[0][2]]) == "OOO":
    print("Jebb")
    exit()

print("Neibb")
