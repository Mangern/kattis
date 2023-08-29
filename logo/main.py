from math import cos, sin, pi
for _ in range(int(input())):
    n = int(input())
    instr = [input().split() for _ in range(n)]
    posx = 0
    posy = 0
    curd = 0

    for t, d in instr:
        d = int(d)
        if t == "fd":
            posx += d * cos(curd * pi / 180)
            posy += d * sin(curd * pi / 180)
