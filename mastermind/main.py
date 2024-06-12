n, a, b = input().split()

r = 0

cnt = {}
my = []

for x, y in zip(a, b):
    if x == y:
        r += 1
    else:
        if x not in cnt:
            cnt[x] = 0
        cnt[x] += 1
        my.append(y)


s = 0
for c in my:
    if c not in cnt:
        continue
    if cnt[c]:
        s += 1
        cnt[c] -= 1

print(r, s)

