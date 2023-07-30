def solve(a,b):
    prod = str(a*b)
    a = str(a)
    b = str(b)

    grid = []

    for i in range(len(b)):
        row = []
        for j in range(len(a)):
            p = int(a[j]) * int(b[i])
            row.append((str(p//10), str(p%10)))
        grid.append(row)

    M = len(a) * 4 + 5
    N = len(b) * 4 + 5

    out = []
    out.append(['+', *('-'*(M-2)), '+'])

    row = []
    row.append('|')
    row.append(' ')
    for c in a:
        row.append(" ")
        row.append(" ")
        row.append(c)
        row.append(" ")
    row.append(" ")
    row.append(" ")
    row.append("|")

    out.append(row)

    for i in range(len(b)):
        x = ['|', ' ']
        y = ['|', ' ']
        z = ['|', ' ']
        w = ['|', ' ']
        for j in range(len(a)):
            x.append('+')
            for ll in range(3):
                x.append('-')

            y.append('|')
            y.append(grid[i][j][0])
            y.append(' ')
            y.append('/')

            z.append('|')
            z.append(' ')
            z.append('/')
            z.append(' ')

            w.append('|')
            w.append('/')
            w.append(' ')
            w.append(grid[i][j][1])

        x.append('+')
        x.append(' ')
        x.append('|')

        y.append('|')
        y.append(' ')
        y.append('|')

        z.append('|')
        z.append(b[i])
        z.append('|')

        w.append('|')
        w.append(' ')
        w.append('|')

        out.append(x)
        out.append(y)
        out.append(z)
        out.append(w)

    row = ['|', ' ']

    for _ in a:
        for c in '+---':
            row.append(c)
    row.append('+')
    row.append(' ')
    row.append('|')

    out.append(row)

    out.append(['|', *(' '*(M-2)) , '|'])

    out.append(['+', *('-'*(M-2)), '+'])

    prod = list(prod)
    ptr = -6

    for _ in range(len(a)):
        out[-2][ptr] = prod.pop()
        if ptr < -6:
            out[-2][ptr+2] = '/'
        ptr -= 4

    ptr = -4

    while prod:
        out[ptr][1] = prod.pop()
        out[ptr+2][1] = '/'
        ptr -= 4

    print("\n".join("".join(o) for o in out))


while True:
    a,b=map(int,input().split())
    if a+b==0:
        break
    solve(a,b)
