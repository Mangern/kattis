from math import gcd
for tc in range(int(input())):
    a = list(map(int, input().split()))[1:]
    n = len(a)
    a.sort()

    g = a[1] - a[0]
    for i in range(n):
        for j in range(i+1, n):
            g = gcd(g, a[j] - a[i])

    y = 0

    for t in a:
        next_mul = ((t + g - 1) // g) * g
        y = max(y, next_mul - t)
    print(f"Case #{tc+1}: {y}")
