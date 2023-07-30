from math import sqrt
L, K, T1, T2, H = map(float,input().split())

if H < L:
    print(f"{H} {H}")
else:

    A = T1
    B = -(T1*K+T2*K+H)
    C = L * K

    x1 = (-B + sqrt(B * B - 4 * A * C))/(2)
    x2 = (-B - sqrt(B * B - 4 * A * C))/(2)
    if x2 < H:
        x2 = x1

    F1 = min(x1,x2)

    if H == L:
        F1 = H

    F2 = max(x1,x2)

    print(f"{F1} {F2}")

