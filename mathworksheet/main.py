f=False
while True:
    n = int(input())
    if n == 0:
        break
    if f:
        print()
    else:
        f = True

    res = [f"{eval(input())}" for _ in range(n)]
    mxl = max(map(len,res))
    rows = [[]]
    res = [" "*(mxl - len(s)) + s for s in res]
    s = 0
    for r in res:
        ad = len(r)
        if s > 0:
            ad += 1
        if s + ad > 50:
            s = 0
            rows.append([])

        rows[-1].append(r)
        s += ad

    for r in rows:
        print(" ".join(r))
