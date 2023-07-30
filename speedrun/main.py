g,n=map(int,input().split())
ts = [list(map(int,input().split())) for _ in range(n)]
ts.sort(key=lambda t: (t[1],t[0]))

pend = -1
for a, b in ts:
    if a >= pend:
        pend = b
        g -= 1

print("YES" if g <= 0 else "NO")
