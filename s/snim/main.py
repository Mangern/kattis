N = 10005
S = list(map(int, input().split()))[1:]
m = int(input())

grundy = [0]*N

for i in range(1, N):
    reach = set()
    for s in S:
        if i - s >= 0:
            reach.add(grundy[i-s])

    mex = 0
    while mex in reach:
        mex += 1

    grundy[i] = mex

for _ in range(m):
    H = list(map(int, input().split()))[1:]
    g = 0
    for h in H:
        g ^= grundy[h]

    print("L" if g == 0 else "W", end="")

print()

