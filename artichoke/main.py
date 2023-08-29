from math import sin, cos, inf
p, a, b, c, d, n = map(int, input().split())

ans = 0.0

def f(k):
    return p * (sin(a*k+b) + cos(c*k + d) + 2)


mx_seen = -inf
for i in range(1, n+1):
    mx_seen = max(mx_seen, f(i))
    ans = max(ans, mx_seen - f(i))

print(ans)
