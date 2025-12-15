from math import log10
C=int(input())

lo=1
hi = 10**15

while lo < hi:
    mid = (lo + hi + 1) // 2
    if mid * log10(mid) <= 10**6 * C:
        lo = mid
    else:
        hi = mid - 1
print(lo)
