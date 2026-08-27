from math import gcd
def base3(n):
    ret = []
    while n:
        ret.append(str(n % 3))
        n //= 3
    return "".join(ret[::-1])

for w in input().split():
    xs = list(map(ord, w))
    g = gcd(*xs)
    print(g)
    print(" ".join(map(base3, map(lambda x: x//g, xs))))
