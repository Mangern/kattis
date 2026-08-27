mini = [None] * 101
maxi = [None] * 101
table = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]

def solve_min(n):
    global mini
    if n == 0:
        return ""


    if mini[n] is not None:
        return mini[n]

    ans = float('inf')
    for i in range(1, 10):
        lz = 0
        while n - table[i] - table[0] * lz >= 0:
            lzs = "0"*lz
            r = solve_min(n - table[i] - table[0] * lz)
            if r == "inf":
                lz += 1
                continue
            res = f"{i}{lzs}{r}"
            ans = min(ans, int(res))
            lz += 1

    mini[n] = f"{ans}"
    return mini[n]

def solve_max(n):
    global maxi
    if n == 0:
        return ""

    if maxi[n] is not None:
        return maxi[n]

    ans = -float('inf') 

    for i in range(1, 10):
        lz = 0
        while n - table[i] - table[0] * lz >= 0:
            lzs = "0"*lz
            r = solve_max(n - table[i] - table[0] * lz)
            if r == "-inf":
                lz += 1
                continue
            res = f"{i}{lzs}{r}"
            ans = max(ans, int(res))
            lz += 1
    maxi[n] = f"{ans}"
    return maxi[n]



for _ in range(int(input())):
    n = int(input())
    print(solve_min(n), solve_max(n))
