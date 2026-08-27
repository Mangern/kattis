from math import log2
EPS = 1e-9
m, n, t = map(int, input().split())

ttime = 0

if t == 1:
    ttime = 1
    for i in range(1,n+1):
        ttime *= i
        if ttime > m:
            break
elif t == 2:
    ttime = 1
    for i in range(1, n+1):
        ttime *= 2
        if ttime > m:
            break
elif t == 3:
    ttime = n * n * n * n
elif t == 4:
    ttime = n * n * n
elif t == 5:
    ttime = n * n
elif t == 6:
    ttime = n * log2(n)
elif t == 7:
    ttime = n

print("AC" if ttime <= m + EPS else "TLE")
