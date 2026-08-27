n = int(input())

finns = []

A = 0
B = 0
C = 0

for i in range(n):
    a,b,c,t = map(int,input().split())
    finns.append((t,a,b,c))
    A += a
    B += b
    C += c

finns.sort()


ans = 0.0

def calc(x):
    return A * x * x + B * x + C

pt = 0.0
prev_t = 0
for i in range(n):
    t,a,b,c = finns[i]
    if t == prev_t:
        A -= a
        B -= b
        C -= c
        continue
    ans = max(ans, calc(pt))
    ans = max(ans, calc(t))

    if A != 0:
        x = -B / (2*A)
        if x >= pt and x <= t:
            ans = max(ans, calc(x))

    A -= a
    B -= b
    C -= c
    prev_t = t
    if t > pt:
        pt = t + 0.0000001

print(f"{ans:.9f}")
