def remap(c):
    if c == '-':
        return '|'
    if c == '|':
        return '-'
    if c == '+':
        return '+'
    return ' '

hs = False
while True:
    n = int(input())
    if not n:
        break
    if hs:
        print()
    else:
        hs = True

    ss = [input() for _ in range(n)]
    m = max(map(len,ss))
    ss = [s + " "*(m-len(s)) for s in ss]
    assert all(len(s) == m for s in ss)
    ss = [[remap(c) for c in s] for s in ss]
    out = [[' ' for _ in range(n)] for _ in range(m)]
    # 0, 0 -> 0, n - 1
    # 0, m - 1 -> m - 1, n - 1
    # n - 1, m - 1 -> m - 1, 0
    for i in range(n):
        for j in range(m):
            out[j][n - 1 - i] = ss[i][j]

    print("\n".join("".join(s).rstrip() for s in out))
