s = input()
n = len(s)

res = [['.' for i in range(4*n+1)] for j in range(5)]

i_ptr = 2

for i,c in enumerate(s):
    res[2][i_ptr] = c
    repc = '*' if i % 3 == 2 else '#'

    pos = [(0,i_ptr),(1,i_ptr+1),(2,i_ptr+2),(3,i_ptr+1),(4,i_ptr),(3,i_ptr-1),(2,i_ptr-2),(1,i_ptr-1)]

    for ii,j in pos:
        if res[ii][j] != '*':
            res[ii][j] = repc
    i_ptr += 4

print("\n".join("".join(l) for l in res))
