order="ROYGP"
s=input()
cnt={k:0 for k in order}
for c in s:
    cnt[c] += 1
for i in range(5):
    vals=sorted(cnt.items(), key=lambda t: t[1])[i:]
    take=vals[0][1]
    out=sorted((x[0] for x in vals), key=lambda c: order.index(c))
    if take > 0:
        print(take, "".join(out))
    else:
        print(take)
    for c in out:
        cnt[c] -= take
