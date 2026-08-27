grid=[input() for _ in range(3)]
cols=["".join(t) for t in zip(*grid)]
diags=["".join([grid[0][0],grid[1][1],grid[2][2]]), 
       "".join([grid[2][0],grid[1][1],grid[0][2]])]
alle=grid+cols+diags
print("X" if "XXX" in alle else "O" if "OOO" in alle else "N")
