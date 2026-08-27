n, k = map(int, input().split())

def gcd(a, b):
    if not b:
        return a
    return gcd(b, a % b)

ints = list(map(int, input().split()))
g = 360

for num in ints:
    g = gcd(g, num)


def test(x):
    if x == g:
        return True
    it = (g * 2)%360
    while it != g:
        if x == it:
            return True
        it += g
        it %= 360
    return False

ks = list(map(int, input().split()))
for x in ks:
    print("YES" if test(x) else "NO")
