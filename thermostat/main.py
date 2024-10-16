from fractions import Fraction


def to_celsius(a, b, v):
    # f(a) = 0
    # f(b) = 100
    # f(t) = ct + d
    # ca + d = 0
    # cb + d = 100
    # cb - ca = 100
    # c = 100 / (b - a)
    # d = -ca = - 100 * a / (b - a)
    # f(v) = 100 / (b - a) * v - 100 * a / (b- a)
    return Fraction(100 * v - 100 * a, b - a)

def from_celsius(a, b, v):
    # f(t) = 100 / (b - a) * t - 100 * a / (b - a)
    # f(x) = v
    # 100 / (b - a) * x - 100 * a / (b - a) = v
    # 100 / (b - a) * x = v + 100 * a / (b - a)
    # x = (b - a) * v / 100 +  a
    return Fraction((b - a), 100) * v + a

n, q = map(int, input().split())
vals = [(0,0)] + [tuple(map(int, input().split())) for _ in range(n)]

for _ in range(q):
    x, y, v = map(int, input().split())

    c = to_celsius(vals[x][0], vals[x][1], v)
    r = from_celsius(vals[y][0], vals[y][1], c)
    print(f"{r.numerator}/{r.denominator}")
