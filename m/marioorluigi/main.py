BIG = 10**18 - 1

def query(l, r):
    print(f"1 {l} {r}")
    return input() == "NO"

def point_query(i):
    print(f"2 {i}")
    return input()

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
        k = max(-(-(tot - 2 * acc) // (2*val)), 1)
        m = l + k - 1
        before = acc + (m - l) * val
        incl = before + val
        c = []
        if m >= 1:
            c.append((abs(2 * before - tot), m))
        if m + 1 <= BIG:
            c.append((abs(2 * incl - tot), m + 1))
        return min(c)[1]


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

segs = [(0, BIG, 1)]

queries_left = 192
while queries_left > 8:
    i = find_midpoint(segs)
    ret = query(i, BIG)
    lft_mul = 1
    rgt_mul = 1
    if ret:
        lft_mul = 1
        rgt_mul = 12
    else:
        lft_mul = 12
        rgt_mul = 1
    segs = split_segs(segs, i - 1, lft_mul, rgt_mul)
    queries_left -= 1

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
for i in pts:
    s = point_query(i)
    if s == "EQUAL":
        continue
    print(f"! {s}")
    exit()
print("WTF")
