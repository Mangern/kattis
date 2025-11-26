from math import floor
n = int(input())
cranes=[tuple(map(int,input().split())) for _ in range(n)]

for xi,yi,hi in cranes:
    near = 10**18
    for xj, yj, hj in cranes:
        if hj <= hi:
            continue
        near = min(near, (xi-xj)*(xi-xj)+(yi-yj)*(yi-yj))
    near = min(near,hi*hi)
    near = near**0.5
    near = floor(near+1e-7)
    print(int(near))
