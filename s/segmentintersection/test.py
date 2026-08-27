import sys
from decimal import Decimal, ROUND_HALF_UP

def rd(x):
    decimal_x = Decimal(str(x))
    rounded_x = decimal_x.quantize(Decimal('0.01'), rounding=ROUND_HALF_UP)
    return float(rounded_x)

def test_case():
    x1, y1, x2, y2, x3, y3, x4, y4 = map(int, input().split())

    if x1 == x2 and x3 == x4:
        if x1 != x3:
            print("none")
            return
        if y2 < y1:
            y1, y2 = y2, y1
        if y4 < y3:
            y3, y4 = y4, y3

        if y4 < y1 or y2 < y3:
            print("none")
            return

        if y4 == y1:
            print("{:.2f} {:.2f}".format(rd(x1), rd(y1)))
            return

        if y2 == y3:
            print("{:.2f} {:.2f}".format(rd(x2), rd(y2)))
            return

        ys = [float(y1), float(y2), float(y3), float(y4)]
        ys.sort()

        print("{:.2f} {:.2f} {:.2f} {:.2f}".format(rd(x1), rd(ys[1]), rd(x1), rd(ys[2])))
        return

    if x1 == x2 or x3 == x4:
        if x3 == x4:
            x1, x3 = x3, x1
            x2, x4 = x4, x2
            y1, y3 = y3, y1
            y2, y4 = y4, y2

        if min(x3, x4) > x1 or max(x3, x4) < x1:
            print("none")
            return

        if y1 > y2:
            y1, y2 = y2, y1

        x3 -= x1
        x4 -= x1
        y3 -= y1
        y4 -= y1
        y2 -= y1

        a = float(y4 - y3) / (x4 - x3)
        b = - a * x3 + y3

        if b < -1e-6 or b - y2 > 1e-6:
            print("none")
            return

        print("{:.2f} {:.2f}".format(rd(x1), rd(b+y1)))
        return

    if x2 < x1:
        x1, x2 = x2, x1
        y1, y2 = y2, y1

    if x4 < x3:
        x3, x4 = x4, x3
        y3, y4 = y4, y3

    if x3 < x1:
        x1, x3 = x3, x1
        x2, x4 = x4, x2
        y1, y3 = y3, y1
        y2, y4 = y4, y2

    if x2 < x3:
        print("none")
        return

    a1 = float(y2 - y1) / (x2 - x1)
    b1 = - a1 * x1 + y1

    a2 = float(y4 - y3) / (x4 - x3)
    b2 = - a2 * x3 + y3

    if (y2 - y1) * (x4 - x3) == (y4 - y3) * (x2 - x1):
        if b1 != b2:
            print("none")
            return

        if x2 == x3:
            print("{:.2f} {:.2f}".format(rd(x3), rd(y3)))
            return

        pts = [
            [float(x1), float(y1)],
            [float(x2), float(y2)],
            [float(x3), float(y3)],
            [float(x4), float(y4)],
        ]

        pts.sort()

        print("{:.2f} {:.2f} {:.2f} {:.2f}".format(rd(pts[1][0]), rd(pts[1][1]), rd(pts[2][0]), rd(pts[2][1])))
        return

    x_inter = (b2 - b1) / (a1 - a2)
    y_inter = a1 * x_inter + b1

    if x_inter == -0.0:
        x_inter = 0.0
    if y_inter == -0.0:
        y_inter = 0.0

    if (x2 == x3 and y2 == y3) or (x2 == x4 and y2 == y4):
        print("{:.2f} {:.2f}".format(rd(x2), rd(y2)))
        return

    if (x1 == x3 and y1 == y3) or (x1 == x4 and y1 == y4):
        print("{:.2f} {:.2f}".format(rd(x1), rd(y1)))
        return

    PREC = 1e-6
    if float(x1) - x_inter > PREC or x_inter - float(x2) > PREC or float(x3) - x_inter > PREC or x_inter - float(x4) > PREC:
        print("none")
        return

    print("{:.2f} {:.2f}".format(rd(x_inter), rd(y_inter)))

def main():
    t = int(input())

    for _ in range(t):
        test_case()

if __name__ == "__main__":
    sys.stdin = open(0)
    main()

