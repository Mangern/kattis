while True:
    n = int(input())
    if not n:
        break
    pts = [tuple(map(int,input().split())) for _ in range(n)]
    mx,my = pts[n>>1]
    stan = 0
    ollie = 0
    for x,y in pts:
        if x == mx or y == my:
            continue
        if (x > mx and y > my) or (x < mx and y < my):
            stan += 1
        if (x < mx and y > my) or (x > mx and y < my):
            ollie += 1

    print(stan,ollie)
