def disp(x, n):
    x %= n
    if x + x > n:
        return x-n
    return x

def count_jumps(n, e):
    p = 0
    ans = 0
    while True:
        p += e
        ans += 1
        if p % n == 0:
            return ans
        e -= 1
    assert False

n, e = map(int, input().split())

cum = 0
prev={}
revnum={}
rev=0
for i in range(n-1,-1,-1):
    rev += i
    rev %= n
    if rev not in revnum:
        revnum[rev] = n - i
jumps=[]
for i in range(n):
    cum += i
    cum %= n
    if i == 0:
        est = 1
    elif cum in prev:
        est = i - prev[cum]
    elif (-cum)%n in revnum:
        want = (-cum)%n
        est = i + 1 + revnum[want]
    else:
        print(f"FAIL {i=}")
        assert False
    jumps.append(est)
    # k = count_jumps(n, i)
    # print(f"{disp(i, n):3d} jumps={k:3d} est={est:3d} cum={disp(cum,n):3d} rev={disp(rev, n):3d}")
    prev[cum] = i
    rev -= i

if n == 1:
    print("infinity")
    exit()

cur = 0
if e >= 2 * n:
    ptr = e % n
    start = ptr
    sm = 0
    triangle_term = 0
    sum_j = 0
    per_round_term = 0
    r = 0
    while True:
        j = jumps[ptr]
        triangle_term += j * (j - 1) // 2
        per_round_term += j * sm
        sum_j += j
        r += 1
        sm += 2 - j
        ptr += 2 - j
        ptr %= n
        if ptr == start:
            break
    if sm >= 0:
        print("infinity")
        exit()

    rounds = (e - 2 * n) // (-sm)

    cur -= rounds * triangle_term
    cur += rounds * per_round_term
    cur += sum_j * (rounds * e + (2 * r - sum_j) * rounds * (rounds - 1) // 2)
    e += rounds * sm



vis=set()
while e > 0:
    # print(cur,e)
    if e in vis:
        print("infinity")
        exit()
    vis.add(e)
    j = jumps[e%n]
    if j > e:
        cur += e * (e + 1) // 2
        break

    # e + (e - 1) + (e - 2) + ... + (e - (j - 1))
    cur += e * j - j * (j - 1) // 2
    e += 2 - j

print(cur)
