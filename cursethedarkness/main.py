for _ in range(int(input())):
    bx,by = map(float,input().split())

    found = False
    for i in range(int(input())):
        x, y = map(float, input().split())

        if (bx-x)**2+(by-y)**2 <= 8*8:
            found = True
    print("light a candle" if found else "curse the darkness")

