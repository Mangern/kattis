#    0
#  1   2
#    3 
#  4   5
#    6

digs = {
    0: [0,1,2,4,5,6],
    1: [2,5],
    2: [0,2,3,4,6],
    3: [0,2,3,5,6],
    4: [1,2,3,5],
    5: [0,1,3,5,6],
    6: [0,1,3,4,5,6],
    7: [0,2,5],
    8: [0,1,2,3,4,5,6],
    9: [0,1,2,3,5,6]
}

def gen_rows(c):
    if c == ':':
        return list(map(lambda l: list(l), [" "*1, " "*1, "o", " "*1, "o", " "*1, " "*1]))
    rows = [[" " for i in range(5)] for j in range(7)]
    fill = digs[int(c)]

    if 0 in fill:
        rows[0] = list("+---+")
    if 1 in fill:
        rows[0][0] = '+'
        rows[1][0] = '|'
        rows[2][0] = '|'
        rows[3][0] = '+'
    if 2 in fill:
        rows[0][4] = '+'
        rows[1][4] = '|'
        rows[2][4] = '|'
        rows[3][4] = '+'
    if 3 in fill:
        rows[3] = list("+---+")
    if 4 in fill:
        rows[3][0] = '+'
        rows[4][0] = '|'
        rows[5][0] = '|'
        rows[6][0] = '+'
    if 5 in fill:
        rows[3][4] = '+'
        rows[4][4] = '|'
        rows[5][4] = '|'
        rows[6][4] = '+'
    if 6 in fill:
        rows[6] = list("+---+")
    return rows






while True:
    s = input()
    if s == "end":
        print(s)
        break

    rows = [[] for i in range(7)]
    for c in s:
        arows = gen_rows(c)
        for a,b in zip(rows,arows):
            if len(a):
                a.append(" ")
                a.append(" ")
            a.extend(b)
    print("\n".join("".join(r) for r in rows))
    print()
    print()
