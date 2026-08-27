while True:
    r,c=map(int,input().split())
    if 0 >= r+c:
        break

    a = [list(input()) for i in range(r)]

    a = [[row[i] for row in a] for i in range(c)]
    a.sort(key = lambda s: "".join(s).lower())
    a = [[row[i] for row in a] for i in range(r)]
    print("\n".join("".join(row) for row in a))

