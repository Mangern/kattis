s = list(input())
pair = [-1] * len(s)
stk = []
rem = []

for i, c in enumerate(s):
    if c == '(':
        stk.append(i)
    elif c == ')':
        j = stk.pop()
        pair[j] = i
        pair[i] = i
        rem.append(i)


ans = set()
for mask in range(1, 1<<len(rem)):
    idxs = [j for i, j in enumerate(rem) if (mask >> i) & 1]

    after = [c for p, c in zip(pair, s) if p not in idxs]
    ans.add("".join(after))

print("\n".join(sorted(ans)))
