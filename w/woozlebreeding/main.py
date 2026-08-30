m1, m2, k = map(int, input().split())

have = []
for x in map(int, input().split()):
    have.append(((x+m1)//2, (x+m2)//2))

reqs = list(map(int, input().split()))
ans = 0
for mask in range(1<<10):
    take = []
    for i in range(10):
        take.append(have[i][(mask >> i) & 1])

    curr = 0
    for r in reqs:
        if r in take:
            take.remove(r)
            curr += 1
    ans = max(ans, curr)
print(ans)
