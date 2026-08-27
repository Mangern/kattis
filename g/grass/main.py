from sys import stdin
from math import sqrt

lines = stdin.readlines()

ptr = 0
while ptr < len(lines):
    n,l,w = map(int,lines[ptr].split())

    sprs = [list(map(int,lin.split())) for lin in lines[ptr+1:ptr+n+1]]

    segs = []

    for spr in sprs:
        x, r = spr
        if 2 * r <= w:
            # Not covering anything useful
            continue
        
        # r ^2 = (w/2) ^2 + dx ^ 2
        rs = r * r - (w*w/4)
        rs = sqrt(rs)
        segs.append((max(-1.0,x-rs), min(l+1,x+rs)))

    segs.sort()
    L = 0
    R = 0
    ans = 0
    i = 0
    while i < len(segs) and L < l:
        while i < len(segs) and segs[i][0] <= L:
            if R < segs[i][1]:
                R = segs[i][1]
            i += 1
        if R <= L:
            break
        L = R
        ans += 1

    if L < l:
        print(-1)
    else:
        print(ans)


    ptr += n+1

