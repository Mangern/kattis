cases = input().split("()")[:-1]

for case in cases:
    toks = [tok[1:-1] for tok in case.split()]

    pairs = [tok.split(",")[::-1] for tok in toks]

    pairs.sort(key=lambda pair: (len(pair[0]), pair[0]))
    has = set()
    ans = []
    bad = False
    for s, v in pairs:
        if len(s) > 0 and s[:-1] not in has:
            bad = True
            break
        ans.append(v)
        has.add(s)

    if bad:
        print("incomplete")
        continue
    
    print(" ".join(ans))
