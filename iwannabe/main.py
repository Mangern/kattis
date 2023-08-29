n, k = map(int, input().split())
poks = [tuple(map(int, input().split())) for _ in range(n)]

added = set()

for i in range(3):
    poks.sort(key = lambda t: -t[i])
    for j in range(k):
        added.add(poks[j])

ans = len(added)
if ans == 3 * k:
    ans -= 1
print(ans)
