from sys import stdin
inp = stdin.read().splitlines()
n=int(inp[0])
cat={}
cnt={}
for line in inp[1:1+n]:
    c,*rest=line.split()
    cnt[c] = 0
    for w in rest[1:]:
        if w not in cat:
            cat[w] = []
        cat[w].append(c)

for line in inp[1+n:]:
    for w in line.split():
        if w in cat:
            for c in cat[w]:
                cnt[c] += 1

mx = max(cnt.values())
#if mx == 0:
#    exit()
ans = [c for c in cnt if cnt[c] == mx]
print("\n".join(sorted(ans)))
