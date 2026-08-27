h_ptr = 1
while True:
    m,n =map(int,input().split())
    if m+n==0:
        break
    a = [list(input()) for i in range(n)]
    for si in range(n):
        for sj in range(m):
            if a[si][sj] == '*':
                break
        else:
            continue
        break
    di = 1 if si == 0 else -1 if si == n-1 else 0
    dj = 1 if sj == 0 else -1 if sj == m-1 else 0
    def ndir(dir,chr):
        if chr == '/':
            if di == 1:
                return (0,-1)
            if di == -1:
                return (0,1)
            if dj == 1:
                return (-1,0)
            if dj == -1:
                return (1,0)
            assert False
        elif chr == '\\':
            if di == 1:
                return (0,1)
            if di == -1:
                return (0,-1)
            if dj == 1:
                return (1,0)
            if dj == -1:
                return (-1,0)
            assert False
        return dir

    while a[si][sj] != 'x':
        si += di
        sj += dj
        di,dj = ndir((di,dj),a[si][sj])
    a[si][sj] = '&'
    print(f"HOUSE {h_ptr}")
    print("\n".join(map(lambda r: "".join(r), a)))
    h_ptr += 1
