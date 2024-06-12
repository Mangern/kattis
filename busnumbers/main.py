n = int(input())
a = list(map(int, input().split()))

mp = [False] * 1000

for x in a:
    mp[x - 1] = True

segs = []
l = -1
for i in range(1000):
    if mp[i] and l == -1:
        l = i+1
    if not mp[i] and l != -1:
        segs.append((l, i))
        l = -1
    if i == 999 and l != -1:
        segs.append((l, i+1))

for l, r in segs:
    if l == r:
        print(l, end=" ")
    elif l + 1 == r:
        print(l, r, end= " ")
    else:
        print(f"{l}-{r}", end=" ")
print()

