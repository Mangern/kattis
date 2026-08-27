cnt={}
for c in input():
    cnt[c] = cnt.get(c, 0) + 1
vals=list(cnt.values())
vals.sort(reverse=True)
print(sum(vals) - sum(vals[:2]))
