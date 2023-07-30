from sys import stdin
from math import sqrt

lines = stdin.readlines()

ptr = 0
while ptr < len(lines):
    n,l,w = map(int,lines[ptr].split())

    sprs = [list(map(int,lin.split())) for lin in lines[ptr+1:ptr+n+1]]

    segs = []

    for spr in sprs:
        if 4 * spr[1] * spr[1] <= w * w:
            continue
        
        rs = spr[1] * spr[1] - (w*w/4)
        rs = sqrt(rs)
        segs.append((max(-1.0,spr[0]-rs), min(l+1,spr[0]+rs)))

    segs.sort()
    L = 0
    R = 0
    ans = 0
    i = 0
    while i < len(segs):
        R = -1
        while i < len(segs) and segs[i][0] <= L:
            if R < segs[i][1]:
                R = segs[i][1]
            else:
                i += 1
        if R == -1:
            break
        L = R
        ans += 1

    if L < l:
        print(-1)
    else:
        print(ans)


    ptr += n+1

