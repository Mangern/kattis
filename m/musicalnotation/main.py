n = int(input())
ln = -1

nots = input().split()
play = []
for nt in nots:
    dur = 1 if len(nt) == 1 else int(nt[1:])
    ln += dur + 1
    play.append((nt[0],dur))

alph = "GFEDCBAgfedcba"
lin = "FDBgea"

out = [list(f"{c}: ") for c in alph]

idx = lambda c: alph.find(c)

for i,c in enumerate(alph):
    chr = '-' if c in lin else ' '
    for j in range(ln):
        out[i].append(chr)

o_ptr = 3
for nt,dur in play:
    for i in range(dur):
        out[idx(nt)][o_ptr] = '*'
        o_ptr += 1
    o_ptr += 1

print("\n".join("".join(l) for l in out))
