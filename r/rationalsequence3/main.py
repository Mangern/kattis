from collections import deque
for _ in range(int(input())):
    k,n=map(int,input().split())
    path = []
    while n > 1:
        if n & 1:
            path.append("R")
        else:
            path.append("L")
        n >>= 1
    path = path[::-1]
    n,d=1,1
    for p in path:
        if p == "L":
            n,d=n,n+d
        else:
            n,d=n+d,d
    print(f"{k} {n}/{d}")

