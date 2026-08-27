best=None
for _ in range(int(input())):
    s = input()
    if len(s)<5:
        continue
    if len(set(s))!=len(s):
        continue
    if best is None:
        best = s
        continue
    if len(best) > len(s) or (len(best) == len(s) and s > best):
        best = s
print("Neibb" if best is None else best)
