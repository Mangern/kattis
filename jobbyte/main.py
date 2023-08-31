n = int(input())
a = list(map(lambda x: int(x) - 1, input().split()))
csz = []

vis = set()
for i, x in enumerate(a):
    if i in vis:
        continue
    vis.add(i)
    j = x
    cnt = 1
    while j != i:
        vis.add(j)
        j = a[j]
        cnt += 1
    csz.append(cnt)

print(sum(csz) - len(csz))
