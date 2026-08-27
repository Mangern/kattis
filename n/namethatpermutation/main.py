from sys import stdin
def solve(n, k, fac):
    # fac[n] = n!
    if n == 0:
        return []

    v = fac[n-1]

    for s, lb in enumerate(range(0, (n-1) * v + 1, v)):
        if lb <= k and k < lb + v:
            s += 1
            ret = solve(n - 1, k - lb, fac)
            ret = [r+1 if r >= s else r for r in ret]
            ret.append(s)
            return ret
    assert False


facs = [1, 1]
for i in range(2, 51):
    facs.append(facs[-1] * i)

for line in stdin:
    n, k = map(int, line.split())
    print(" ".join(map(str, solve(n, k, facs)[::-1])))
