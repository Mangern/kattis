tc = 1
while True:
    W,n=map(int,input().split())
    if W+n == 0:
        break
    ws = [input().split() for _ in range(n)]
    ws = [(x,int(y)) for x,y in ws]
    cmax = max(y for x,y in ws)

    ans = 0
    cr_width = 0
    cr_height = 0

    for w,c in ws:
        P = 8 + (40 * (c - 4) + cmax - 5) // (cmax - 4)
        width = (9*len(w) * P + 15) // 16
        if cr_width > 0 and cr_width + 10 + width <= W:
            cr_width += 10 + width
            cr_height = max(cr_height, P)
        else:
            ans += cr_height
            cr_width = width
            cr_height = P

    ans += cr_height
    print(f"CLOUD {tc}: {ans}")
    tc += 1
