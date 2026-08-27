from math import gcd
def solve_rep(rep):
    mul = 10**len(rep)
    # mul x = int(rep) + 0.reprepreprep
    #       = int(rep) + x
    # (mul - 1)x = int(rep)
    # x = int(rep) / (mul - 1)
    p = int(rep)
    q = mul - 1
    g = gcd(p,q)
    return p//g,q//g

while True:
    s = input()

    if s == "0":
        break

    s = s[:-3]

    ld = len(s) - 2

    ans = (0, float('inf'))

    for i in range(1,ld+1):
        # Assume suffix of length i is repeating
        beg = s[2:-i]
        beg = 0 if not beg else int(beg)
        mul = 10**(ld-i)
        rem = s[-i:]
        p,q = solve_rep(rem)
        # beg + p/q = (beg*q + p) / q
        p = beg * q + p
        q *= mul
        g = gcd(p,q)
        p //= g
        q //= g

        if q < ans[-1]:
            ans = (p,q)
    print(f"{ans[0]}/{ans[1]}")
