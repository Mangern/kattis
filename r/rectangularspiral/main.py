for _ in range(int(input())):
    t,x,y=map(int,input().split())
    if y > x:
        print(t, 2, x, y)
        continue

    a = x - y + 5
    b = x + 2
    c = y - 2 + a

    if not (3 < a < b < c):
        print(t, "NO PATH")
        continue

    print(t, 6, 1, 2, 3, a, b, c)
