from math import gcd, lcm

def find_period(p, s):
    n = len(p)
    start = [((s >> i) & 1) for i in range(n)]
    a = [x for x in start]
    period = 0
    while True:
        period += 1
        b = [a[p[i]-1] for i in range(n)]
        if b == start:
            return period
        a = b

def find_periods(p):
    n = len(p)
    ps={}
    for mask in range(1<<n):
        x = find_period(p, mask)
        ps[x] = ps.get(x, 0) + 1
    return sorted(ps.items())

def find_component_periods(n):
    ps={}
    for d in range(1,n+1):
        if n % d == 0:
            here = 2**d
            for d2 in ps:
                if d % d2 == 0:
                    here -= ps[d2]
            ps[d] = here
    return sorted(ps.items())

def find_components(p):
    n=len(p)
    comp = [-1]*n
    T = 0
    for i in range(n):
        if comp[i] == -1:
            ptr = p[i] - 1
            comp[i] = T
            while ptr != i:
                comp[ptr] = T
                ptr = p[ptr] - 1
            T += 1
    sz = [0]*T
    for i in range(n):
        sz[comp[i]] += 1
    return sorted(sz)

def find_periods_fast(p):
    comps = find_components(p)
    curr_ps = {p: cnt for p, cnt in find_component_periods(comps[0])}

    for c in comps[1:]:
        periods = find_component_periods(c)
        new_ps = {}
        for p1 in curr_ps:
            for p2, c2 in periods:
                k = lcm(p1, p2)
                new_ps[k] = new_ps.get(k, 0) + curr_ps[p1] * c2
        curr_ps = new_ps
    return sorted(curr_ps.items())

def find_periods_faster(p):
    comps = find_components(p)
    l = 1
    for c in comps:
        l = lcm(l, c)

    ps = []
    cnts = []
    for d in range(1, l+1):
        if l % d == 0:
            ps.append(d)
            cnts.append(2**sum(gcd(c, d) for c in comps))

    for i in range(len(ps)):
        for j in range(i):
            if ps[i] % ps[j] == 0:
                cnts[i] -= cnts[j]
    return list(zip(ps, cnts))

def make_deranged(n):
    return list(range(2, n+1)) + [1]

def perm_from_components(comps):
    n = sum(comps)
    start = 1
    ret = []
    for c in comps:
        ret += list(range(start+1, start + c)) + [start]
        start += c
    return ret

# [1] -> (1,) + (2,)
# [2, 3, 1] -> (1, 3) + (2, 6)
# [2, 3, 1, 4] -> (1, 3) + (4, 12)

# for 2, 3, 3, 3, 4
# we get periods
#   [1, 2, 3, 4, 6, 12]
# and cumulative counts:
#   [2**5, 2**7, 2**11, 2**9, 2**13, 2**15]
# with respect to divisor relationship
#   2**5 == 2**nC
# where does 2**7 come from?
#  from the original we have the pairs:
#  1, 2 (from 2 and 4) 
#  2, 1 (from 2 and 3) - 3 times
#  2, 1 (from 2 and 4)
#  2, 2 (from 2 and 4)
#  total product here is 2**7 ...

# 2**11 corresponding to LCM == 3
#  1, 3 (from 2 and 3) - 3 times
#  1, 3 (from 3 and 3) - 3 times
#  3, 3 (from 3 and 3) - 3 times
#  3, 1 (from 3 and 
# ... hard to get this to add up

# gcd with  1: [1, 1, 1, 1, 1]: sum = 5
# gcd with  2: [2, 1, 1, 1, 2]: sum = 7
# gcd with  3: [1, 3, 3, 3, 1]: sum = 11
# gcd with  4: [2, 1, 1, 1, 4]: sum = 9
# gcd with  6: [2, 3, 3, 3, 2]: sum = 13
# gcd with 12: [2, 3, 3, 3, 4]: sum = 15

# So for each divisor of the LCM we sum the result of gcd with component sizes
# and use that sum as a exponent for 2.

# So to solve the original problem:
# Let L be the biggest period.
# If the set of periods is not exactly the divisors of L, fail.
# Apply cumulative addition on the counts.
# for i in range(n):
#   for j in range(i):
#     if per[i] % per[j] == 0:
#        cum[i] += cnt[j]
#
# The resulting counts should be powers of 2, if not fail.
# Apply log2 to each count. Let d[i] be the i'th divisor of L. Assume d is sorted.
# Let c[i] be the log2 of the cumulative count for the i'th divisor.
# The number of components C is c[0].
# Our equations are:
# sum(gcd(comp[0], d[0]), gcd(comp[1], d[0]), ..., gcd(comp[C-1], d[0])) == c[0]
# ...
# sum(gcd(comp[0], d[i]), gcd(comp[1], d[i]), ..., gcd(comp[C-1], d[i])) == c[i]


# Observations: 
# - Is in general overdetermined
# - First equation trivial since we already used it to determine C
# - In the last equation the gcd vanishes, since d[n-1] == L
# - The last equation says that the sum of component sizes must be N
# Lets try something on the example above.
# ok, c[0] == 5
# d[1] = 2, c[1] = 7. c[1] - c[0] = 2. 2 / (2 - 1) == 2
# So in fact we know that 2 elements must be divisible by 2.
# next, d[2] = 3, c[2] = 11. 2 does not divide 3 so it's not interesting.
# But 1 does, co we calculate c[2] - c[0] = 6. 6 / (3 - 1) == 3.
# So 3 elements must be divisible by 3.
# next, d[3] = 4, c[3] = 9.
# 9 - 7 = 2. 9 - 5 = 4.

# n=2 -> (1, 2) + (2, 2)
# n=3 -> (1, 3) + (2, 6)
# Combined -> (1, 2, 3, 6) + (4, 4, 12, 12)
#   == (1*1, 2*1, 1*3, 2*3) + (2*2, 2*2, 2*6, 2*6)
# comps = list(map(int, input().split()))
comps = [2, 3, 5, 7, 11, 13, 17, 19, 23]
perm = perm_from_components(comps)
# perm = list(range(2, 101)) + [1]

# print(perm, find_components(perm))
# periods = find_periods_fast(perm)
# ps_real, cnts_real = zip(*periods)
# print(ps_real)
# print(cnts_real)

periods = find_periods_faster(perm)
ps, cnts = zip(*periods)
# print(ps)
# print(cnts)


# if ps != ps_real or cnts != cnts_real:
#     print("FAILL")

print(len(perm), len(ps))
print(" ".join(map(str, ps)))
print(" ".join(map(str, cnts)))
print(ps[-1])

# Theory:
#  If the permutation has only one component, 
#  we get a period for each divisor d | n, with
#  number of elements equal to 2^d - sum(number els for d' | d)
#  Seems to be correct.
#  What about multiple groups?
#  We see that combining two groups means:
#      Getting new periods equal to the LCM of the individual periods
#      Getting new periods counts equal to the products of the individual counts
