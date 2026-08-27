# find c such that
# sum di / (si - c) == t
# 

n, t = map(int, input().split())

eps = 1e-9

readings = [tuple(map(int,input().split())) for _ in range(n)]

# s + c >= 0
# c >= -s
lo = float(max(-s for d, s in readings))
hi = 1e10

while hi - lo > eps:
    c = (hi + lo) / 2

    est = sum(d / (s + c) for d, s in readings)
    if est < t:
        # underestimated time => overestimated speed
        hi = c
    else:
        lo = c

print(lo)
