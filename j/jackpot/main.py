from math import lcm

for _ in range(int(input())):
    n = int(input())
    ws = list(map(int, input().split()))

    big = 10**9

    l = 1
    for w in ws:
        l = lcm(l, w)
        if l > big:
            break

    print(l if l <= big else "More than a billion.")


