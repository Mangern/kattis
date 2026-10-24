from math import log
for _ in range(int(input())):
    ng, dg, nt, dt = map(int,input().split())
    if ng == dg:
        print(1)
        continue
    k = max(1, int(log(1 - nt/dt) / log(1 - ng/dg)) - 1)
    while True:
        if (dg - ng)**k * dt <= (dt - nt) * dg**k:
            print(k)
            break
        k += 1
