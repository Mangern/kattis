n, p = map(int, input().split())

has = [[False]*13, [False]*13, [False]*13, [False]*13]

ans = -1

for i in range(n):
    c, k = map(int, input().split())
    c -= 1
    k -= 1

    if ans != -1:
        continue

    has[c][k] = True

    # k-2, k-1, k
    # k-1, k, k+1
    # k, k+1, k+2
    for x in range(k-2, k+1):
        if x + 2 >= 13:
            continue
        if x < 0:
            continue
        if has[c][x] and has[c][x+1] and has[c][x+2]:
            ans = i

print("Neibb" if ans == -1 else max(1, ans - p + 1))
