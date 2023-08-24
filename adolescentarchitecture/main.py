from math import pi, sqrt
def get_area(s):
    t,val = s.split()
    val = float(val)
    if t == "cube":
        return val * val
    return val * val * pi


def solve():
    n = int(input())

    stuff = [input() for i in range(n)]

    stuff.sort(key=get_area)

    for x, y in zip(stuff[::-1], stuff[::-1][1:]):
        tx, vx = x.split()
        ty, vy = y.split()
        vx, vy = map(float, (vx,vy))
        if tx == ty:
            continue
        if tx == "cube":
            if 2 * vy > vx:
                print("impossible")
                return
        else:
            if vy * sqrt(2) > 2 * vx:
                print("impossible")
                return
    print("\n".join(stuff))
solve()
