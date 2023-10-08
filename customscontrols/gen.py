from random import shuffle, choice, sample
N = 100000
M = 199995
K = 50000

free = list(range(2, N+1))
shuffle(free)
conn = [1]

t = ["1607" for i in range(N)]

edges = []

adj = {}

while free:
    u = free.pop()
    v = choice(conn)
    edges.append((u,v))
    conn.append(u)

    if u > v:
        u,v=v,u

    if u not in adj:
        adj[u] = []
    adj[u].append(v)

while len(edges) < M:
    u, v = sample(conn, k=2)

    if u > v:
        u,v=v,u

    if u in adj and v in adj[u]:
        continue
    edges.append((u,v))
    if u not in adj:
        adj[u] = []
    adj[u].append(v)



print(f"{N} {M} {K}")
print(" ".join(t))
for u, v in edges:
    print(f"{u} {v}")
