from collections import deque

mxN = 10000

is_prime = [True for _ in range(mxN)]
is_prime[0] = False
is_prime[1] = False
for i in range(2,mxN):
    if not is_prime[i]:
        continue
    for j in range(i*i,mxN,i):
        is_prime[j] = False

adj = [[] for _ in range(mxN)]

for i in range(1000, mxN):
    if not is_prime[i]:
        continue
    s = str(i)
    for pos in range(4):
        for dig in range(10):
            nnum = int(s[:pos]+chr(ord("0")+dig)+s[pos+1:])
            if nnum <= i or nnum < 1000 or (not is_prime[nnum]):
                continue
            adj[i].append(nnum)
            adj[nnum].append(i)

for _ in range(int(input())):
    a,b=map(int,input().split())
    q = deque()
    q.append((a,0))

    vis = set()
    vis.add(a)

    ans = "Impossible"
    while len(q):
        u,d = q.popleft()
        if u == b:
            ans = d
            break
        for v in adj[u]:
            if v not in vis:
                vis.add(v)
                q.append((v,d+1))

        s = str(u)
    print(ans)
