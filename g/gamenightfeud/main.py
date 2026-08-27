a,b=input().split()
grid = [input() for _ in range(3)]
to_check = []
for i in range(3):
    # rows
    to_check.append([(i, j) for j in range(3)])
    # cols
    to_check.append([(j, i) for j in range(3)])
to_check.append([(0, 0), (1, 1), (2, 2)])
to_check.append([(0, 2), (1, 1), (2, 0)])

win_x = False
win_o = False
num_x = 0
num_o = 0

for check in to_check:
    cs = [grid[i][j] for i, j in check]
    if all(x == 'X' for x in cs):
        win_x = True
    if all(x == 'O' for x in cs):
        win_o = True

for row in grid:
    num_x += sum(1 for x in row if x == 'X')
    num_o += sum(1 for x in row if x == 'O')

if num_x not in [num_o, num_o + 1] or (win_x and win_o):
    print("Invalid Game")
elif win_x:
    print(a)
elif win_o:
    print(b)
elif num_x == 5 and num_o == 4:
    print("Draw")
else:
    print("In-Progress")
