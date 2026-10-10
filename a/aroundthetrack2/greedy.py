from math import atan2, pi
from random import shuffle

n, m = map(int, input().split())

xs, ys = zip(*[tuple(map(int, input().split())) for _ in range(n)])

adj = [[] for _ in range(n)]

for _ in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

for u in range(n):
    shuffle(adj[u])

def turn_angle(u1, u2, u3):
    x1, y1 = xs[u1], ys[u1]
    x2, y2 = xs[u2], ys[u2]
    x3, y3 = xs[u3], ys[u3]

    h1 = atan2(y2 - y1, x2 - x1)
    h2 = atan2(y3 - y2, x3 - x2)

    if (x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2) >= 0:
        # left turn
        while h2 < h1:
            h2 += 2 * pi
        return h2 - h1
    else:
        # right turn
        while h1 < h2:
            h1 += 2 * pi
        return h1 - h2

rem = set()
circuit = []
def euler_circuit(u, prev=None):
    if prev is not None:
        adj[u].sort(key=lambda v: turn_angle(prev, u, v))

    for v in adj[u]:
        key = (min(u, v), max(u, v))
        if key in rem:
            continue
        rem.add(key)
        euler_circuit(v, u)
        circuit.append((u,v))

euler_circuit(0)

circuit = circuit[::-1]

ans = 0

for i in range(m):
    u1, u2 = circuit[i]
    _, u3 = circuit[(i + 1) % m]

    ans += turn_angle(u1, u2, u3)

print(ans)
