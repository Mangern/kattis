def isqrt(x):
    s = int(x**0.5)
    if (s - 1) * (s - 1) == x:
        return s - 1
    if s * s == x:
        return s
    if (s + 1) * (s + 1) == x:
        return s + 1
    assert False

for _ in range(int(input())):
    nm = input().split()

    n = isqrt(len(nm))

    ok = True
    for i in range(n):
        for j in range(n):
            myl = len(nm[i * n + j])
            ok = True
            for ni, nj in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]:
                if ni < 0 or ni >= n or nj < 0 or nj >= n:
                    continue
                if len(nm[ni * n + nj]) != myl:
                    ok = False
                    break
            if ok:
                print(nm[i * n + j])
                break
        if ok:
            break
    if not ok:
        print("Name Not Found")
