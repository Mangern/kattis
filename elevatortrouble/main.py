# s + x * u - y * d = g
# g - s = x * u - y * d

from collections import deque

f, s, g, u, d = map(int,input().split())

if s == g:
    print(0)
    exit()

dist = [None for i in range(f)]
s -= 1
g -= 1

dist[s] = 0
q = deque()

q.append(s)

while q:
    x = q.popleft()
    if x == g:
        break
    for v in [x + u, x - d]:
        if 0 <= v <= f - 1:
            if dist[v] is None:
                dist[v] = dist[x] + 1
                q.append(v)

print(dist[g] if dist[g] is not None else "use the stairs")
