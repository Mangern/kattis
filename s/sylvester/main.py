def query(n, x, y):
    if n == 1:
        return 1
    n2 = n//2
    if x < n2 and y < n2:
        return query(n2, x, y)
    elif x < n2:
        return query(n2, x, y - n2)
    elif y < n2:
        return query(n2, x - n2, y)
    else:
        return -query(n2, x - n2, y - n2)

for _ in range(int(input())):
    n,sx,sy,w,h = map(int,input().split())

    for y in range(sy, sy+h):
        for x in range(sx, sx+w):
            print(query(n, x, y), end=" ")
        print()
    print()
