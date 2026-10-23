# import matplotlib.pyplot as plt
from random import randint, random
from math import log2

# BIG = 10**3 - 1
BIG = 10**18 - 1

GT = randint(0, BIG)
num_lies = 0
#GT = 69

print(f"Ground truth: {GT}")

def query(l, r):
    global GT
    global num_lies

    # r == BIG
    ret = l <= GT
    if randint(1, 13) == 1:
        num_lies += 1
        ret = not ret
    return ret

def point_query(i):
    if i > GT:
        return False
    return True

def find_midpoint(segs):
    tot = 0
    for l, r, val in segs:
        tot += (r - l + 1) * val

    acc = 0
    for l, r, val in segs:
        here = val * (r - l + 1)
        if (acc + here) * 2 < tot:
            acc += here
            continue

        # acc + (i - l + 1) * val <= tot / 2
        # i <= (tot / 2 - acc)/val + l - 1
        # TODO: Consider ceil?
        k = max(-(-(tot - 2 * acc) // (2*val)), 1)
        m = l + k - 1
        before = acc + (m - l) * val
        incl = before + val
        c = []
        if m >= 1:
            c.append((abs(2 * before - tot), m))
        if m + 1 <= BIG:
            c.append((abs(2 * incl - tot), m + 1))
        # if i > l:
        #     alt1 = acc + (i - l + 1) * val
        #     alt2 = acc + (i - l) * val
        #     if abs(2 * alt2 - tot) < abs(2 * alt1 - tot):
        #         return i - 1
        return min(c)[1]

def find_midpoint_alt(segs):
    max_seg = (0, 0, 0)
    for l, r, v in segs:
        max_seg = max(max_seg, (v, l, r))
    v, l, r = max_seg
    return (l+r)//2

def find_randpoint(segs):
    x = random()
    acc = 0
    for l, r, v in segs:
        acc += v * (r - l + 1)
        if acc >= x:
            break
    return randint(l, r)


def find_midpoint_wgt(segs):
    max_seg = (0, 0, 0)
    for l, r, v in segs:
        max_seg = max(max_seg, (v, l, r))
    v, l, r = max_seg
    i = find_midpoint(segs)

    if l <= i <= r:
        return i
    if i < l:
        return l
    return r


def split_segs(segs, idx, lft_mul, rgt_mul):
    # idx is the last index on the left side
    lft = []
    rgt = []

    for l, r, v in segs:
        if r < idx:
            lft.append((l, r, v * lft_mul))
        elif idx < l:
            rgt.append((l, r, v * rgt_mul))
        else:
            lft.append((l, idx, v * lft_mul))
            if idx + 1 <= r:
                rgt.append((idx + 1, r, v * rgt_mul))
    return lft + rgt

def normalize_segs(segs):
    mn = segs[0][2]
    for l, r, v in segs:
        mn = min(mn, v)
    if mn > 1:
        return [(l, r, v // mn) for l, r, v in segs]
    else:
        return segs

segs = [(0, BIG, 1)]

def viz(segs):
    xs = []
    ys = []
    plt.clf()
    mval = 0
    for l, r, val in segs:
        plt.plot([l, r], [val, val])
        mval = max(mval, val)
    i = find_midpoint(segs)
    plt.plot([i, i], [0, mval*1.1])
    plt.ion()
    plt.show()
    input()

queries_left = 192
while queries_left > 8:
    #viz(segs)
    i = find_midpoint(segs)
    # print(f"Mid: {find_midpoint(segs)}, Info: {find_information_point(segs)}")
    ret = query(i, BIG)
    lft_mul = 1
    rgt_mul = 1
    if ret:
        # All >= i gets 12/13
        # All < i gets 1/13
        lft_mul = 1
        rgt_mul = 12
    else:
        # All > i gets 1/13
        # All <= i gets 12/13
        lft_mul = 12
        rgt_mul = 1
    segs = split_segs(segs, i - 1, lft_mul, rgt_mul)
    queries_left -= 1

#viz(segs)

segs.sort(key=lambda t: t[2], reverse=True)
ptr = 0
pts = []
for _ in range(queries_left):
    l, r, v = segs[ptr]
    pts.append(r)
    if l == r:
        ptr += 1
    else:
        segs[ptr] = (l, r - 1, v)

pts.sort(reverse=True)
print(abs(GT-find_midpoint(segs)))
print(f"Num lies: {num_lies}")
for i in pts:
    if point_query(i):
        if i != GT:
            print("WRONG ANSWER")
        else:
            print(f"The answer is: {i}")
        exit()

print("Could not find the answer :(")
print(f"Tested points (distance): {[i - GT for i in pts]}")
